class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len,vector<int>(len));
        string ans;

        for(int l = 0 ; l < len ; l++){
            for(int i = 0 ; i + l < len; i++){
                int j = i + l;
                if(l == 0)  dp[i][j] = 1;
                else if( l == 1)    dp[i][j] =(s[i] == s[j]);
                else{
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j] && l+ 1> ans.size()){
                    ans = s.substr(i,l+1);
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    bool divisorGame(int N) {
        return N%2== 0;
    }
};

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


