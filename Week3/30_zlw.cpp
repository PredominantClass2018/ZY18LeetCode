

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    Solution() = default;

public:
    //5.最长回文字符串
    //https://leetcode-cn.com/problems/longest-palindromic-substring/
    string longestPalindrome(string s) {
        // abaccaba
        //A
 

        stack<string::const_iterator> iter_stack;
        vector<string >vec;

        //双指针法，往里夹      iter1 >>回文串<< iter2
        for (string::const_iterator iter1 = s.cbegin(); iter1 != s.cend(); ++iter1)
        {
            for (string::const_iterator iter2 = s.cend() - 1; iter2 != iter1; --iter2)
            {
                if (*iter1 == *iter2)      //头尾相等
                {
                    if (judge_palindromic(string(iter1, iter2+1))) {
                        //是回文，那么break,
                        vec.push_back(string(iter1, iter2+1));
                        break;
                    }
                }
                
            }
        }
       
        //返回vec里存的最长的回文串

        if (vec.empty())    //如果没有回文，则返回第一个字符
            return string(s.begin(),s.begin()+1);

        vector<string>::iterator index = vec.begin();
        int max_length = 0;
        for (vector<string>::iterator iter = vec.begin(); iter != vec.end(); ++iter)
        {
            if (iter->length() > max_length)
            {
                index = iter;
                max_length = iter->length();
            }
        }

        return *index;
        
    }
    //判断是否是回文的函数
    bool judge_palindromic(string tmps) {
        string::const_iterator iter1 = tmps.cbegin();
        string::const_iterator iter2 = tmps.cend() - 1;
        while ( iter2 > iter1)
        {
            if (*iter1 != *iter2)
                return false;
            ++iter1;
            --iter2;
        }
        return true;
    }

    //1025.除数博弈
    //https://leetcode-cn.com/problems/divisor-game/
    bool divisorGame(int N) {
        if (N % 2 == 0)
            return true;
        return false;


    }

    //547. 朋友圈
    //https://leetcode-cn.com/problems/friend-circles/
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

int main(void)
{
  
 

    Solution s = Solution();
   //cout << s.longestPalindrome("cccabaccc") << endl;
    //cout << s.longestPalindrome("cbbd") << endl;
    //cout << s.judge_palindromic("cbbc") << endl;
   
    return 0;
}