bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int i,j;
    float s;
    for(i=x1;i<=x2;i++)
    {    for(j=y1;j<=y2;j++)
        {
            s=sqrt((i-x_center)*(i-x_center)+(j-y_center)*(j-y_center));
            if(s<=radius)
                return true;
        }
    }
    return false;
}



int search(int* nums, int numsSize, int target){
    int left=0,right=numsSize-1;
    int mid;
    while(left<right)
    {
        mid=(left+right)/2;
        if(target==nums[mid])   return mid;
        if(target<nums[mid])
            right=mid-1;
        else
            left=mid+1;
    }
    if(target==nums[left]) return left;
    return -1;
}




void reverse(int* nums,int start,int end)
{
    int temp;
    while(start<end)
    {
        temp=nums[start];
        nums[start]=nums[end];
        nums[end]=temp;
        start++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k){
    k%=numsSize;
    reverse(nums,0,numsSize-1);
    reverse(nums,0,k-1);
    reverse(nums,k,numsSize-1);
}
