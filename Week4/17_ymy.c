//1401

bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    int x,y,dist;
    if(x_center>x2) x=x2;
    else if(x_center<x1) x=x1;
    else x=x_center;
    if(y_center > y2) y = y2;
    else if(y_center < y1) y = y1;
    else y = y_center;
    dist=(x-x_center)*(x-x_center)+(y-y_center)*(y-y_center);
    if(dist<=radius*radius) return true;
    else return false;
    /*
    int dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0;
    int dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0;
    return dx * dx + dy * dy <= radius * radius;
    */
}




//704

int search(int* nums, int numsSize, int target){
    /*int i;
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        return i;
    }
    return -1;*/
    int left=0,right=numsSize-1;
    int mid;
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(nums[mid]==target) return mid;
        else if(nums[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}



//189

void reverse(int* nums, int numsSize)
{
    int i=0,iTmp=0;
    for(i=0;i<numsSize/2;i++)
    {
        iTmp=nums[i];
        nums[i]=nums[numsSize-1-i];
        nums[numsSize-1-i]=iTmp;
    }
    return ;
}
void rotate(int* nums, int numsSize, int k){
    /*
    int i,t;
    while(k)
    {
        t=nums[numsSize-1];
        for(i = numsSize - 1; i > 0; i--)
        {
            nums[i]=nums[i-1];
        }
        nums[0]=t;
        k--;
    }
    return nums;
    
    //使用反转
    if((nums==NULL)||(numsSize<=1)) return ;
    k = k % numsSize;
    reverse(&nums[0],numsSize);
    reverse(&nums[0],k);
    reverse(&nums[k],numsSize-k);
    return ;
    */

    //循环替换
    int     i       = 0;
    int     iTmp    = 0;
    int     iLast   = 0;
    int     iStart  = 0;
    int     iCount  = 0;
    int     iCur    = 0;
    int     iDest   = 0;
    if((NULL == nums) || (numsSize <= 1)) return;
    k = k % numsSize;
    for(iStart = 0; iCount < numsSize; iStart++)
    {
        iLast = nums[iStart];
        iCur = iStart; 
        do
        {
            iDest = (iCur + k) % numsSize;
            iTmp = nums[iDest];
            nums[iDest] = iLast;
            iLast = iTmp;

            iCur = iDest;
            iCount += 1;
        } while(iCur != iStart); 
    }
    return;
}