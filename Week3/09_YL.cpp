1025.除数博弈
class Solution {
public:
	bool divisorGame(int N) {
		return N % 2 == 0;
	}
};

547.朋友圈
class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		int count = 0;
		vector<bool>Mark(M.size());
		for (int i = 0; i<M.size(); ++i){
			if (Mark[i] == 0){
				dfs(M, Mark, i);
				count++;
			}
		}
		return count;
	}

	void dfs(vector<vector<int>>& M, vector<bool>& Mark, int i){
		Mark[i] = 1;//访问标志，已经访问过了，置1，下次不再访问。
		for (int j = 0; j<M.size(); ++j){
			if (M[i][j] == 1 && Mark[j] == 0){
				dfs(M, Mark, j);
			}
		}
	}
};

5.最长回文子串
class Solution {
	//dp[i][j]=(s[i]==s[j]) and (dp[i+1][j-1])  j-1-(i+1)+1<2,最中间必须要有一个或零个字符。
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int len = 1, start = 0;
		if (n == 0) return "";
		vector<vector<bool>> dp(n, vector<bool>(n));
		for (int i = 0; i<n; ++i){
			dp[i][i] = true;
		}
		for (int j = 1; j<n; ++j){
			for (int i = 0; i<j; ++i){
				if (s[i] != s[j]) dp[i][j] = false;
				else{
					if (j - i<3) dp[i][j] = true;  //确立边界条件
					else      dp[i][j] = dp[i + 1][j - 1];
				}

				if (dp[i][j] && j - i + 1>len){
					len = j - i + 1;
					start = i;
				}
			}
		}
		return s.substr(start, len);
	}
};