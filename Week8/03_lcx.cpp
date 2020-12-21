//LeetCode 537
//https://leetcode-cn.com/problems/complex-number-multiplication/
class Solution {
private:
	complex<int> fun(const string& str){
		int a = 0, b = 0;
		bool flag = false;
		int i = 0, j = 0;
		if(str[i] == '-'){
			flag = true;
			++i;
			++j;
		}
		while('0' <= str[j] && str[j] <= '9')
			++j;
		a = stoi(string(str.begin() + i, str.begin() + j));
		if(flag)
			a = -a;
		i = ++j;
		flag = false;
		if(str[i] == '-'){
			flag = true;
			++i;
			++j;
		}
		while('0' <= str[j] && str[j] <= '9')
			++j;
		b = stoi(string(str.begin() + i, str.begin() + j));
		if(flag)
			b = -b;
		return complex<int>(a, b);
	}
public:
    string complexNumberMultiply(string a, string b) {
		auto ans = fun(a) * fun(b);
		return string(to_string(ans.real()) + '+' + to_string(ans.imag()) + 'i');
    }
};


//LeetCode 153
//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
		if(nums.size() == 1)
			return nums[0];
		int left = 0, right = nums.size() - 1, mid = 0;
		if(nums[right] > nums[0])
			return nums[0];
		while(left <= right){
			mid = left + (right - left) / 2;
			if(nums[mid] > nums[mid + 1])
				return nums[mid + 1];
			else if(nums[mid] < nums[mid - 1])
				return nums[mid];
			if(nums[mid] > nums[0])
				left = mid + 1;
			else
				right = mid - 1;
		}
		return -1;
    }
};

