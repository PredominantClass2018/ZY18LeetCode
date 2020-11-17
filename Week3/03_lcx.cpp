//LeetCode 5
//https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		string temp(2 * s.size() + 3, '#');
		int m = 0, n = 0;
		for (int i = 0; i < s.size(); ++i)
			temp[2 * (i + 1)] = s[i];
		temp[0] = '@';
		temp[temp.size() - 1] = '$';
		for (int i = 1; i < temp.size() - 1; ++i) {
			int j = 1;
			while (temp[i - j] == temp[i + j])
				++j;
			if (j > m) {
				m = j;
				n = i;
			}
		}
		string ans(m - 1, ' ');
		for (int i = 0, j = n - m + 1; j < n + m; ++j)
			if (temp[j] != '#')
				ans[i++] = temp[j];
		return ans;
	}
};

//LeetCode 1025
//https://leetcode-cn.com/problems/divisor-game/submissions/
class Solution {
public:
	bool divisorGame(int N) {
		return !(N & 1);
	}
};

//LeetCode 547
//https://leetcode-cn.com/problems/friend-circles/
class Solution {
private:
	vector<int> v;
	void initial(int size) {
		v.assign(size, 0);
		for (int i = 0; i < size; ++i)
			v[i] = i;
		return;
	}
	int find(int n) {
		return v[n] == n ? n : v[n] = this->find(v[n]);
	}
public:
	int findCircleNum(vector<vector<int>>& M) {
		int ans = M.size();
		this->initial(M.size());
		for (int i = 1; i < M.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (M[i][j]) {
					int t1 = this->find(i);
					int t2 = this->find(j);
					if (t1 != t2)
						--ans;
					v[t1] = t2;
				}
		return ans;
	}
};
