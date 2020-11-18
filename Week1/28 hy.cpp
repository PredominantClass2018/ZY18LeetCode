第一题
int sumOddLengthSubarrays(int* arr, int arrSize){
    int i, j, sum = 0;
    int length = 1;
    while(length <= arrSize)
    {
        for(i = 0; i < arrSize - length + 1; i++)
        {
            for(j = i; j < i + length; j++)
            {
                sum += arr[j];
            }
        }
        length += 2;
    }
    return sum;
}



第二题
bool threeConsecutiveOdds(int* arr, int arrSize){
    int count=0;
    int i;
    for(i=0;i<arrSize;i++)
    {
        if(arr[i]%2)
        {
            count++;
        }
        else
        {
            count=0;
        }
        if(count==3)
        {
            return true;
        }
    }
    return false;
}


第三题
#define MIN(a,b) (a)>(b)?(b):(a)
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,j,dp[triangleSize][triangleSize];
    int tmp=0;
    printf("triangleSize=%d,*triangleColSize=%d\n",triangleSize,*triangleColSize);
    if(triangleSize==1)
    return triangle[0][0];
    for(j=0;j<triangleSize;j++)
    {
        dp[triangleSize-1][j]=triangle[triangleSize-1][j];
    }
    for(i=triangleSize-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            tmp=MIN(dp[i+1][j],dp[i+1][j+1]);
            dp[i][j]=tmp+triangle[i][j];
        }
    }
    return dp[0][0];
}

