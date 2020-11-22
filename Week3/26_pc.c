//1、除数博弈
class Solution {
public:
    bool divisorGame(int N) {
        if (N%2 == 0)   return true;
        else    return false;
    }
};

//2、朋友圈
 class Solution {
 public:
     int findCircleNum(vector<vector<int>>& M) {
         int N=M.size();
         vector<int> visit(N,0);
         int count=0,temp;
         queue<int> Que;
         for(int i=0;i<N;++i){
             if(!visit[i]){
                 count++;
                 Que.push(i);
                 while(!Que.empty()){
                     temp=Que.front();
                     Que.pop();
                     visit[temp]=1;
                     for(int j=0;j<N;++j)
                         if(M[temp][j] && !visit[j])
                             Que.push(j);
                 }
             }
         }
         return count;
     }
 };


//3、求最大回文子串
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string rets;
        int left,right,len;//左边界 右边界 串长
        vector<vector<int>> dp(n, vector<int> (n));
        for(len = 0; len < n; ++len){
            for(left = 0; left+len < n; ++left){
                right = left + len;
                dp[left][right] = (s[left] == s[right]);//对角线置1 单个字母必是回文串
                if (len > 1)
                    dp[left][right] = ((s[left] == s[right]) && dp[left+1][right-1]);
                if (dp[left][right] && len+1 > rets.size())
                    rets = s.substr(left,len+1);
            }
        }
        return rets;
    }
};
