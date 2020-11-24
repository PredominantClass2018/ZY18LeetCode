//5
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> f(n, vector<int>(n));
        string str;
        for (int len = 0; len < n; len++) {
            for (int i = 0; i + len < n; i++) {
                int j = i + len;
                if (len == 0) f[i][j] = 1;
                else if (len == 1)
                    f[i][j] = (s[i] == s[j]);
                else
                    f[i][j] = (s[i] == s[j] && f[i + 1][j - 1]);
                if (f[i][j] && len + 1 > str.size())
                    str = s.substr(i, len + 1);
            }
        }
        return str;
    }
};
//547
class Solution {
public:
    int find(vector<int>& parent, int i) {
        while (parent[i] == -1) {
            return i;
        }
        return find(parent, parent[i]);
    }

    void _union(vector<int>& parent, int x, int y) {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if (xset != yset) {
            parent[xset] = yset;
        }
    }


    int findCircleNum(vector<vector<int>>& M) {
        vector<int> parent(M.size(), -1);
        for (int i = 0; i < M.size(); i++) {
            for (int j = i; j < M.size(); j++) {
                if (M[i][j] == 1 && i != j) {
                    _union(parent, i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < M.size(); i++) {
            if (parent[i] == -1) {
                count++;
            }
        }
        return count;
    }
};
//1025
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> v(N + 1, false);
        v[1] = false;
        v[2] = true;
        for (int i = 3; i <= N; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && v[i - j] == false) {
                    v[i] = true;
                    break;
                }
            }
        }
        return v[N];
    }
};