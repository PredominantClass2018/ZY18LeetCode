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
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int middle = (left + right) / 2;
            if (nums[middle] < nums[right])
                right = middle;
            else
                left = middle + 1;
        }
        return nums[left];
    }
};

