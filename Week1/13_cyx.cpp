//120. 三角形最小路径和
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
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

//1550. 存在连续三个奇数的数组
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
         int cnt = 0;
         for(auto x:arr){
             if (x%2){
                 cnt++;
             }else{
                 cnt = 0;
             }
             if(cnt >= 3){
                 return true;
             }
         }
         return false;
    }
};

//1588. 所有奇数长度子数组的和
int sumOddLengthSubarrays(int* arr, int arrSize)
{
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
