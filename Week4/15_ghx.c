/*bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++) {
        for(int j = y1; j <= y2; j++) {
            float distance = sqrt((i - x_center) * (i - x_center) + (j - y_center) * (j - y_center));
            if(distance <= radius) {
                return true;
            }
        }
    }
    
    return false;
}*/


/*int search(int* nums, int numsSize, int target){
   int left=0;
    int right=numsSize-1;
    int mid=(left+right)/2;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            left=mid+1;
        else right=mid-1;
    }
    return -1;
}*/

void rotate(int* nums, int numsSize, int k){
       if(!nums || numsSize == 0)
        return;
    k = k % numsSize;
    int cnt = 0, start = 0, cur;
    int prev, next, tmp;
    while(cnt < numsSize){
        cur = start;
        prev = nums[start];
        do{
            next = (cur + k) % numsSize;
            tmp = nums[next];
            nums[next] = prev;
            prev = tmp;
            cur = next;
            cnt++;
        }while(start != cur);
        start++;
    }
}
