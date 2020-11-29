1
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    if((x_center>=x1&&x_center<=x2)&&(y_center>=y1&&y_center<=y2))
        return true;
    
    else if((x_center<x1)&&(y_center>=y1&&y_center<=y2))
    {
        if((x1-x_center)<=radius)   return true;
        else    return false; 
    }
    else if((x_center>x2)&&(y_center>=y1&&y_center<=y2))
    {
        if((x_center-x2)<=radius)   return true;
        else    return false;
    }
    else if((y_center>y2)&&(x_center>=x1&&x_center<=x2))
    {
        if((y_center-y2)<=radius)   return true;
        else    return false;
    }
    else if((y_center<y1)&&(x_center>=x1&&x_center<=x2))
    {
        if((y1-y_center)<=radius)   return true;
        else    return false; 
    }
    else
    {
        if ((pow((x_center-x2),2)+pow((y_center-y2),2))<=pow(radius,2))  
            return true;
        else if((pow((x_center-x2),2)+pow((y1-y_center),2))<=pow(radius,2)) 
            return true;
        else if((pow((x1-x_center),2)+pow((y_center-y2),2))<=pow(radius,2)) 
            return true;
        else if((pow((x1-x_center),2)+pow((y1-y_center),2))<=pow(radius,2)) 
            return true;
        else return false;
    }       
}

2
int search(int* nums, int numsSize, int target){
    int left=0,right=numsSize-1,i;
    while(left<=right)
    {
        i=(left+right)/2;
        if(nums[i]==target)
            return i;
        else if(nums[i]<target)
            left=i+1;
        else right=i-1;
    }
    return -1;
    
}

3
//使用额外的数组 
void rotate(int* nums, int numsSize, int k){
    int temp[numsSize];
    int i=0;
    for(int i=0;i<numsSize;i++)
    {
        temp[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=temp[i];
    }
}


