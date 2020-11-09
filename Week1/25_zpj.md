~~~c
//是否有子数组属于奇数组
bool threeConsecutiveOdds(int* arr, int arrSize){
    int i;
    for( i = 2; i < arrSize; i++){
        if((arr[i]&1) & (arr[i-1]&1) & (arr[i-2]&1))
            return true;
    }
    return false;
}
~~~

~~~c
//奇数组和
int sumOddLengthSubarrays(int* arr, int arrSize){
    int res = 0;
    int lodd,leven,rodd,reven;
    int i;
    for(i = 0; i < arrSize; i++){
        lodd = (i+1)/2;
        leven = i/2+1;
        rodd = (arrSize - i)/2;
        reven = (arrSize - i + 1)/2;
        res  += (lodd*rodd + leven*reven)*arr[i];
    }
    return res;
}
~~~

~~~c
//最短三角形路径
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int f[triangleSize];
    memset(f, 0, sizeof(f));
    f[0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        f[i] = f[i - 1] + triangle[i][i];
        for (int j = i - 1; j > 0; --j) {
            f[j] = fmin(f[j - 1], f[j]) + triangle[i][j];
        }
        f[0] += triangle[i][0];
    }
    int ret = f[0];
    for (int i = 1; i < triangleSize; i++) ret = fmin(ret, f[i]);
    return ret;
}
~~~


