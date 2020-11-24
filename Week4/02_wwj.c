

/*1401圆和矩形是否有重叠*/

bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int i,j;
    for(i=x1;i<=x2;i++)
        for(j=y1;j<=y2;j++)
        {
            if((pow((i-x_center),2)+pow((j-y_center),2))<=pow(radius,2))
                return true;
        }
    return false;
}

/*704二分查找*/
int search(int* nums, int numsSize, int target){
    int i,j,p=0;
    j=numsSize-1;
    while(i<j)
    {
        p=(i+j)/2;
        if(nums[p]==target) return p;
        else if(nums[p]>target) j=p;
        else i=p+1;
    }
    if(nums[i]==target) return i;
    else return -1;
}
 
/*189旋转数组*/
 void rotate(int* nums, int numsSize, int k){
    int buf;
    int temp[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        buf=(i+k)%numsSize;
        temp[buf]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=temp[i];
    }
}


