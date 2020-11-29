1
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    if (x_center>=x1 && x_center<=x2){
        if(y_center-y2>radius || y1-y_center>radius)
            return false;
        else return true;
    }
    if (y_center>=y1 && y_center<=y2){
        if(x1-x_center>radius || x_center-x2>radius)
            return false;
        else return true;
    }
    if ((x1-x_center)*(x1-x_center)+(y1-y_center)*(y1-y_center)<=(radius*radius))
        return true;
    if ((x1-x_center)*(x1-x_center)+(y2-y_center)*(y2-y_center)<=(radius*radius))
        return true;
    if ((x2-x_center)*(x2-x_center)+(y1-y_center)*(y1-y_center)<=(radius*radius))
        return true;
    if ((x2-x_center)*(x2-x_center)+(y2-y_center)*(y2-y_center)<=(radius*radius))
        return true;
    return false;
}


2
int search(int* nums, int numsSize, int target){
    int i=0;
    while(i<numsSize){
        for (i=0;i<numsSize;i++){
            if (nums[i]==target)
                return i;
        }
    }
    return -1;
}

/*¶ş·Ö²éÕÒ*/ 
int search(int* nums, int numsSize, int target){
    int low,high,mid;
    low=0;
    high=numsSize-1;
    while(low<=high){
        mid=(low+high)/2;
        if (nums[mid]==target)
            return mid;
        else if (nums[mid]>target)
            high=mid-1;
        else if (nums[mid]<target)
            low=mid+1;
    }
    return -1;
}




3
void rotate(int* nums, int numsSize, int k){
    int temp[numsSize],i;;
    for(i=0;i<numsSize;i++)
    {
        temp[(i+k)%numsSize]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        nums[i]=temp[i];
    }
}

