1.
int cmp(const void* c1, const void* c2) {
    return *(int*)c1 - *(int*)c2;
}

int findBestValue(int* arr, int arrSize, int target){
    if (arr == NULL) {
        return 0;
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    int sum = 0;
    for (int i = 0; i < arrSize; i++) {
        int x = (target - sum) / (arrSize - i);
        if (x < arr[i]) {
            double t = ((double)(target - sum))/(arrSize - i);
            if (t - x > 0.5) {
                return x + 1;
            } else {
                return x;
            }
        }
        sum += arr[i];
    }
    return arr[arrSize - 1];
}






2.
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int* back;
    back = (int*)malloc(sizeof(int)*2);
    back[0] = -1;
    back[1] = -1;
    *returnSize = 2;
    if(numsSize == 0)    return back;
    if(nums[0] > target || nums[numsSize-1] < target )    return back;
    int mid, start=0, end=numsSize-1, flag = -1;
    while(start <= end){
        mid = (start+end)/2;
        if(nums[mid] == target){
            flag = mid;
            break;
        }
        if(nums[mid] < target){
            start = mid + 1;
        }
        if(nums[mid] > target){
            end = mid - 1;
        }
    }
    if(flag == -1){
        return back;
    }
    back[0] = back[1] = flag;
    int pre = flag; 
    while(pre >= start){
        if(nums[pre] != target){
            break;
        }
        back[0] = pre;
        pre -= 1;
    }
    while(flag <= end){
        if(nums[flag] != target){
            break;
        }
        back[1] = flag;
        flag += 1;
    }

    return back;
}
