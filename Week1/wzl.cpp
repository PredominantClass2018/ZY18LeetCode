


//1.所有奇数长度子数组的和 
int sumOddLengthSubarrays(int* arr, int arrSize)
 {
 	int sum=0,length=1;
 	while(length<=arrSize)
 	{
 		for(int i=0;i<arrSize-length+1;i++)
 		{
 			for(int j=i;j<i+length;j++)
 			{
 				sum+=arr[j];
			 }
		 }
		 length+=2;
	 }
    return sum;
}

//2. 存在连续三个奇数的数组
 bool threeConsecutiveOdds(int* arr, int arrSize)
{
 	int i=0,j=0,l=0;
 	for(i=0;i<arrSize-2;i++)
 	{
 		if(arr[i]%2==1)
 		{
            if(arr[i+1]%2==1)
            {
            	if(arr[i+2]%2==1)
            	{
            		return true;
				}
			}
		 }
	 }
	 return false;
}

//3. 三角形最小路径和 

int compare(int a,int b)
{
	if(a>b) return b;
	else return a;
}


int minimumTotal(int** triangle, int  triangleSize, int* triangleColSize){
	for(int i=triangleSize-2;i>0;i--)
	{
		for(int j=0;j<i+1;j++)
		{
			triangle[i][j]=triangle[i][j]+compare(triangle[i+1][j],triangle[i+1][j+1]);
			
		}
	}
	return triangle[0][0];
}
