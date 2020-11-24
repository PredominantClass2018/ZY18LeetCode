1.class Solution
{
 public:
    string longestPalindrome(string s) 
    {
        if(s.length()==1) return s;
        string rev=s;
        string res;
        std::reverse(rev.begin(),rev.end());
        int len=0;
        if(rev==s) return s;
        for(int i=0;i<s.length();++i)
        {
            string temp;
            for(int j=i;j<s.length();++j)
            {
                temp=temp+s[j];
                if(s.find(temp)!=-1)
                {
                    string str=temp;
                    std::reverse(str.begin(),str.end());
                    if(str==temp)
                    {
                      if(temp.length()>len)
                      {
                          len=temp.length();
                          res=temp;
                      }
                    }
                }

            }
        }
        return res;

    }
};


2.class Solution {
public:
    bool divisorGame(int N) {
        if(N%2==0)
         return true;
        else
         return false; 

    }
};
3.class Solution {
 public:
     void DFS(vector<vector<int>>& M,vector<int> &visit,int n){
         visit[n]=1;
         for(int j=0;j<M.size();++j)
             if(M[n][j] && !visit[j])
                 DFS(M,visit,j);
     }
     int findCircleNum(vector<vector<int>>& M) {
         int N=M.size();
         vector<int> visit(M.size(),0);
         int count=0;
         for(int i=0;i<N;++i){
             if(!visit[i]){
                 DFS(M,visit,i);
                 count++;
             }
         }
         return count;
     }
 };


