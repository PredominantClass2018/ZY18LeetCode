#include "iostream"
#include "string"
#include "vector"
class Solution {
public:
    int find(vector<int>& Vec, int n) {
        if (Vec[n] == -1)
            return n;
        return find(Vec, Vec[n]);
    }

    void Union(vector<int>& Vec, int m, int n) {
        int parent_m = find(Vec, m);
        int parent_n = find(Vec, n);
        if (parent_m != parent_n)
            Vec[parent_m] = parent_n;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> parent(N, -1);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (M[i][j] == 1 && i != j)
                    Union(parent, i, j);
            }
        }
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (parent[i] == -1)
                count++;
        return count;
    }
}; 
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len));
        string ans;
        for (int l = 0; l < len; l++) {
            for (int i = 0; i + l < len; i++) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = s[i] == s[j];
                }
                else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
void main() {
    string s = "aaaa";
    Solution f;
    s=f.longestPalindrome(s);
    cout << s;
}
/*class Solution {
public:
    bool divisorGame(int N) {
        return N % 2 == 0;
    }
};*/