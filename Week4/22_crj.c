===================圆和矩形是否有重叠
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int minx,miny,d;
    if( x1 <= x_center <= x2 )
    {
        minx=0;
    }
    if( x_center < x1 )
    {
        minx=x_center-x1;
    }
    if( x2 < x_center)
    {
        minx=x_center-x2;
    }
    if( y1 <= y_center <= y2)
    {
        miny=0;
    }
    if ( y_center < y1  )
    {
        miny=y_center-y1;
    }
    if(  y2 < y_center) 
    {
        miny=y_center-y2;
    }
    return minx*minx+miny*miny <= radius*radius;

}
======================二分查找
int search(int* nums, int numsSize, int target){
    int i;
    for (i=0 ;i<numsSize ; i++)
    {
        if(nums[i]==target)
        {
            return i;
        }
    }
    return -1;
}
====================旋转数组
void reverse(int *num, int start, int end )
{
    int t;
    while(start<end)
    {
        t=num[start];
        num[start]=num[end];
        num[end]=t;
        start++;
        end--;
    }
    
}

void rotate(int *num, int numsize,int k)
{
    k=k%numsize;
    reverse(num,0,numsize-1);
    reverse(num,0,k-1);
    reverse(num,k,numsize-1);
}