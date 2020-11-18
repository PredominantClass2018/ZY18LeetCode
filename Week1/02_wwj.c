

/*1588所有奇数子长度的和*/

int sumOddLengthSubarrays(int* arr, int arrSize){
	int k,j,sum1,p,count;
	k=0;
	j=1;
	p=0;
	count=0;
	sum1=0;
	
	while(j<=arrSize)
	{
		for(k=0;k<=arrSize-j;)
		{
			for(count=0;count<j;count++)
			{
				sum1+=arr[p];
				p++;
			}
			p=++k;
		}
		j+=2;
		p=0;
	}
	return sum1;

/*1550存在连续三个奇数的数组*/
bool threeConsecutiveOdds(int* arr, int arrSize){
	int flag=0;
	int j;
	for(j=0;j<arrSize;j++)
	{
		if(arr[j]%2==1)
		{
			flag++;
		}
		else flag=0;
		if(flag==3) return true;
		if(flag==0&&j==arrSize-2) return false;
	}
	return false;
	
/*120三角形最小路径和*/

 int min(int a,int b)
{
    if(a>=b) return b;
    else return a;
}

 int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,j;
    for(i=triangleSize-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            triangle[i][j]=triangle[i][j]+min(triangle[i+1][j],triangle[i+1][j+1]);
        }
    }
    return triangle[0][0];
}


