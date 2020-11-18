//LeetCode 1550
//题目链接：https://leetcode-cn.com/problems/three-consecutive-odds/
class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		int n = 0;
		auto the_end = arr.end();
		for (auto it = arr.begin(); it != the_end; it++) {
			if (*it & 1)
				n++;
			else
				n = 0;
			if (n == 3)
				return true;
		}
		return false;
	}
};

//LeetCode 1588
//题目链接：https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
			ans += (((i + 2) / 2) * ((arr.size() - i + 1) / 2) + ((i + 1) / 2) * ((arr.size() - i) / 2)) * arr[i];
		return ans;
	}
};

//LeetCode 120
//题目链接：https://leetcode-cn.com/problems/triangle/
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		vector<int>& dp = triangle[triangle.size() - 1];
		for (int i = triangle.size() - 2; i >= 0; --i)
			for (int j = 0; j <= i; ++j)
				dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
		return dp[0];
	}
};
