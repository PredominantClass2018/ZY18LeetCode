1
bool threeConsecutiveOdds(int* arr, int arrSize){
    int i;
    int flag=0;
    for(i=0;i+2<arrSize;i++)
    {
        if((arr[i]%2)!=0)
        {
            if((arr[i+1]%2)!=0)
            {
                if((arr[i+2]%2)!=0)
                {
                    flag=3;
                }
            }
        }
    }
            if(flag==3)
        {
            return true;
        }
        else
        {
            return false;
        }
}
2
int sumOddLengthSubarrays(int* arr, int arrSize)
{
    int sum=0;
    for(int i=1;i<=arrSize;i+=2)
        for(int j=0;j<arrSize;j++)
            for(int k=0;j+i-1<arrSize&&k<i;k++)
                sum+=arr[j+k];
    return sum;
}
3
int min(int x,int y){
    return (x < y) ? x : y;
}

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){

    int dp[triangleSize];
    int i,j;

    for(i = 0;i < triangleSize;i++){
        dp[i] = triangle[triangleSize-1][i];
    }


    for(i = triangleSize-2;i >= 0;i--){
        for(j = 0;j <= i;j++){
            dp[j] = min(triangle[i][j] + dp[j],triangle[i][j] + dp[j+1]);
        }
    }

    return dp[0];

}


