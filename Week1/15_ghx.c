bool isodds(int num){
	if(num%2==1) return 1;
	else return 0;
}
bool threeConsecutiveOdds(int* arr, int arrSize){
	int i;
	for(i=0;i<=arrSize-3;i++)
	{
		if(isodds(arr[i])&&isodds(arr[i+1])&&isodds(arr[i+2])) return true;
		
	}
	return false; 
}



int sumOddLengthSubarrays(int* arr, int arrSize){
	int i,j,k;
	int sum=0;
	for(i=1;i<=arrSize;i+=2)//遍历所有奇数长度 例如：1、3、5、7 
	{
		for(j=0;j<arrSize-i+1;j++)//遍历子数组 
		{
			for(k=0;k<i;k++)
				sum+=arr[k+j];
		}
	}
	return sum;
}



int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){//从下往上 

    int n=triangleSize;
    int* tmp=triangle[n-1];
    for(int i=n-2;i>=0;i--)
    {
        int m=triangleColSize[i];
        for(int j=0;j<m;j++)
        {
            int min=tmp[j]<tmp[j+1]?tmp[j]:tmp[j+1];
            tmp[j]=triangle[i][j]+min;
        }
    }
    return tmp[0];  
}
