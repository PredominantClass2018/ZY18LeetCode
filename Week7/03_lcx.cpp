//LeetCode 1419
//https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking/
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
		vector<int> v(5, 0);
		for(const auto& x : croakOfFrogs){
			switch(x){
				case 'c':
					if(v[4])
						--v[4];
					++v[0];
					break;
				case 'r':
					if(!v[0])
						return -1;
					--v[0];
					++v[1];
					break;
				case 'o':
					if(!v[1])
						return -1;
					--v[1];
					++v[2];
					break;
				case 'a':
					if(!v[2])
						return -1;
					--v[2];
					++v[3];
					break;
				case 'k':
					if(!v[3])
						return -1;
					--v[3];
					++v[4];
					break;
			}
		}
		return (v[0] | v[1] | v[2] | v[3]) ? -1 : v[4];
    }
};


//LeetCode 1124
//https://leetcode-cn.com/problems/longest-well-performing-interval/
class Solution {
public:
    int longestWPI(vector<int>& hours) {
		vector<int> sum(hours.size() + 1, 0);
		stack<int> stk;
		int ans = 0;
		for(int i = 0; i < hours.size(); ++i)
			sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : -1);
		for(int i = 0; i < sum.size() - 1; ++i)
			if(!i || sum[i] < sum[stk.top()])
				stk.push(i);
		for(int j = sum.size() - 1; j >= 0 && !stk.empty(); --j){
			while(!stk.empty() && sum[j] > sum[stk.top()]){
				ans = max(ans, j - stk.top());
				stk.pop();
			}
		}
		return ans;
    }
};

