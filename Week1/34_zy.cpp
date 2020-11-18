class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for(int num: arr){
            if(num % 2 != 0){
                cnt++;
                if(cnt == 3) return true;
            }else{
                cnt = 0;
            }
        }
        return false;
    }
};
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
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
    for (int i = triangle.size() - 2; i >= 0; i--)
        for (int j = 0; j < triangle[i].size(); j++)
            triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    return triangle[0][0];
    }
};