//LeetCode 120
class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		if (n == 1) return triangle[0][0];
		vector<vector<int>> Mark(n, vector<int>(n));
		for (int j = 0; j <= n - 1; ++j){
			Mark[n - 1][j] = triangle[n - 1][j];
		}
		for (int i = n - 2; i >= 0; --i){
			for (int j = 0; j <= i; ++j){
				Mark[i][j] = min(Mark[i + 1][j], Mark[i + 1][j + 1]) + triangle[i][j];
			}
		}
		return Mark[0][0];
	}
};



//LeetCode 1550
class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		if (arr.size()<3)  return false;

		for (int i = 0; i<arr.size() - 2; ++i){
			if ((arr[i] % 2 == 1) && (arr[i + 1] % 2 == 1) && (arr[i + 2] % 2 == 1))
				return true;
		}
		return false;

	}
};


//1588
class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int n = arr.size(), sum = 0;
		for (int i = 1; i <= n; i = i + 2)
			for (int j = 0; j + i <= n; ++j)
				for (int k = j; k<j + i; ++k)
					sum += arr.at(k);
		return sum;
	}
};
