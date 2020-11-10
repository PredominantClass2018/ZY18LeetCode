int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int f[triangleSize][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        f[i][0] = f[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[i][j] = fmin(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
        }
        f[i][i] = f[i - 1][i - 1] + triangle[i][i];
    }
    int ret = f[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++)
        ret = fmin(ret, f[triangleSize - 1][i]);
    return ret;
}

bool threeConsecutiveOdds(int* arr, int arrSize){

    for(int i=0;i<arrSize-2;i++)
    {
        if((arr[i]&1)&(arr[i+1]&1)&(arr[i+2]&1))
        {
            return true;
        }
    }
    return false;
}
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        if (arr.empty())
            return 0;
        int ret = 0;

        vector<int> sum(arr.size() + 1, 0);
        for (int i = 0; i < arr.size(); i++) {
            sum[i + 1] = sum[i] + arr[i];
        }

        // 开始位置不断向右移动
        for (int start = 0; start < arr.size(); start++) {
            // 对于每个开始位置，计算接下来奇数个连续数值的累加和
            for (int len = 1; len <= arr.size(); len += 2) {
                int end = start + len;
                if (end > arr.size())
                    break;
                else
                    ret += sum[end] - sum[start];
            }
        }
        return ret;
    }
};

