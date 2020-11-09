1.bool is_odd(int num)
{
    return (num % 2 == 1) ? 1 : 0;
}


bool threeConsecutiveOdds(int *arr, int arrSize)
{
    for (int i = 0; i <= arrSize - 3 ; i++) {
        if (is_odd(arr[i]) && is_odd(arr[i + 1]) && is_odd(arr[i + 2])) {
            return true;
        }
    }

    return false;
}

2.int sumOddLengthSubarrays(int* arr, int arrSize){
    int i;
    int j;
    int m;
    int res = 0;
    for (i = 0; i < arrSize; i++) {
        for (j = 1; j < arrSize - i + 1; j += 2) {
            for (m = i; m < i + j; m++) {
                res = res + arr[m];
            }
        }

    }
    return res;

}

3.int min(int x,int y){
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