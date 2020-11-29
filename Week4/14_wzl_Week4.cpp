//1401. 圆和矩形是否有重叠
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            float distance = sqrt((i - x_center) * (i - x_center) + (j - y_center) * (j - y_center));
            if(distance <= radius) {
                return true;
            }
        }
    }
    
    return false;
}

//704. 二分查找
int search(int* nums, int numsSize, int target){
    int i;
    int left = 0;
    int right = numsSize - 1;
    int mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    return -1;
}


//189. 旋转数组

void reverse(int *arr,int start,int end)
{
    int temp;
    while(start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(numsSize == 1 || k%numsSize == 0) return nums;
    k = k%numsSize;
    int start = 0,end = numsSize - 1;
    reverse(nums,start ,end);
    reverse(nums,0,k-1);
    reverse(nums,k,end);

}



