//1588
class Solution {
    int s[110];
public:
    /*1
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++){
            for(int j = i;j < n; j+=2){
                for(int k = i; k <= j; k++) res += arr[k];
            }
        }
        return res;
    }
    */
    //2
    int sumOddLengthSubarrays(vector<int> &arr) {
        int n = arr.size();
        int res = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i-1] + arr[i-1];
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j+=2){
                res += (s[j]-s[i-1]);
            }
        }
        return res;
    }


};

//1550
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for(int i = 0; i + 2 < arr.size(); i++)
            if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i+2]%2==1) return true;
        return false;
    }
};

//120
class Solution {
    int dp[10010];
public:
    int minimumTotal(vector<vector<int>>& vec) {
        int n = vec.size();
        for(int i = 0; i < vec[n-1].size();i++) dp[i] = vec[n-1][i];
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j < vec[i].size(); j++){
                dp[j] = min(dp[j],dp[j+1]) + vec[i][j];
            }
        }
        return dp[0];
    }
};
