bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int x,y;
    if(x_center<x1)
        x=x1-x_center;
    else if(x_center>x2)
        x=x_center-x2;
    else
        x=0;

    if(y_center<y1)
        y=y1-y_center;
    else if(y_center>y2)
        y=y_center-y2;
    else
        y=0;

    if(x*x+y*y<=radius*radius)
        return true;
    else
        return false;
}




int search(int* nums, int numsSize, int target){
    int n=(numsSize-1)/2;
    int left=0,right=numsSize-1;
    if(nums[0]==target)
        return 0;
    if(nums[numsSize-1]==target)
        return numsSize-1;
    while(left<=right)
    {
        if(nums[n]==target)
        {
            return n;
        }
        else if(nums[n]>target)
        {
            right=n-1;
            n=(right+left)/2;
        }
        else if(nums[n]<target)
        {
            left=n+1;
            n=(right+left)/2;
        }
    }
    return -1;
}



void rotate(int* nums, int numsSize, int k){
    int i,j;
    int n=k%numsSize;
    for(i=0;i<numsSize/2;i++)
    {
        j=nums[i];
        nums[i]=nums[numsSize-i-1];
        nums[numsSize-i-1]=j;
    }

    for(i=0;i<n/2;i++)
    {
        j=nums[i];
        nums[i]=nums[n-i-1];
        nums[n-i-1]=j;
    }

    for(i=n;i<(n+numsSize)/2;i++)
    {
        j=nums[i];
        nums[i]=nums[numsSize-i-1+n];
        nums[numsSize-i-1+n]=j;
    }
}