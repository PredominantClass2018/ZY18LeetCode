1.
bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2){
    float i,j,x;
    int flag=0;
	float x_c=x_center,y_c=y_center;
	float r=radius;
	float r1;
    r1=r*r;
	for(i=x1;i<=x2;i=i+0.5)
	
	{
		for(j=y1;j<=y2;j=j+0.5)
		{
			x=(x_c-i)*(x_c-i)+(y_c-j)*(y_c-j);
			if(x<=r1)
				{
					flag=1;
					break;
				}
			
		}
		if(flag==1)
		{
			break;
		}
	}
	if(flag==1)
	{
		return true;
	}
    else
    {
        return false;
    }
}
2.
    int low=0,high=numsSize-1;
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        else {if(nums[mid]>target) high=mid-1;
        else low=mid+1;}
    }
    return(-1);
}
3.
void charge(int* nums,int begin,int end){
    int temp;
    while(begin<end)
    {
        temp=nums[begin];
        nums[begin]=nums[end];
        nums[end]=temp;
        begin++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k){
    k=k%numsSize;
    charge(nums,0,numsSize-1);
    charge(nums,0,k-1);
    charge(nums,k,numsSize-1);

}
