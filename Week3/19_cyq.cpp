/*
¶¯Ì¬¹æ»®
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
*/


class Solution {
public:

    pair<int, int> expandAroundCenter(const string& s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            --left;
            ++right;
        }
        return {left+1,right-1};
    }

    string longestPalindrome(string s) {
        
        int start=0,end=0;
        for(int i=0;i<s.size();++i){
            auto [left1, right1] = expandAroundCenter(s,i,i);
            auto [left2, right2] = expandAroundCenter(s,i,i+1);
            if(right1 - left1 > end - start){
                start=left1;
                end=right1;
            }
            if(right2 - left2 > end - start){
                start=left2;
                end=right2;
            }
        }
        return s.substr(start, end-start+1);
    }
};


class Solution {
public:
    bool divisorGame(int N) {
        return N%2==0
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        UnionFind uf(N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i != j && M[i][j] == 1) {
                    uf.unite(i, j);
                }
            }
        }

        return uf.count();
    }

private:
    class UnionFind {
    public:
        UnionFind(int n) {    
            parent = vector<int>(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
            
        int count() {    
            int res = 0;
            for (int i = 0; i < parent.size(); i++) {
                res += (parent[i] == i);
            }

            return res;
        }

        void unite(int x, int y) {
            auto px = find(x);
            auto py = find(y);
            if (px != py) {
                parent[px] = py;
            }
        } 

        int find(int x) {
            if (x == parent[x]) {
                return x;
            }

            return find(parent[x]);
        }  
    private:
        vector<int> parent;
    };
};

