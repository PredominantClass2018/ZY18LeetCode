/****************
binary-search
****************/

/*********  version 1  memory consumption 7M    *********/  
/*int search(int* nums, int numsSize, int target){
    for(int i=0;i<numsSize;++i)
        if(nums[i]==target)
            return i;
    
    return -1;
}
*/

/*********  version 2  memory consumption 6.9M    *********/  
/*int search(int* nums, int numsSize, int target){
    int left=0;
    int right=numsSize-1;
    int mid=(left+right)/2;
    
    for(int i=0;;++i){
        if(nums[mid]==target)   return mid;
        if(nums[mid]<target){
            left=mid+1;
        }
        if(nums[mid]>target){
            right=mid-1;
        }
        mid=(left+right)/2;
        if(right<left)  return -1;
    }
} */

/*********  version 3  memory consumption 7.2M    *********/  
/*int search(int* nums, int numsSize, int target){
    int mid,left=0,right=numsSize-1;
    while(left<=right){
        mid=left+(right-left)/2;
        if(nums[mid]==target)   return mid;
        if(target<nums[mid])    right=mid-1;
        else left=mid+1;
    }
    return -1;
}*/
