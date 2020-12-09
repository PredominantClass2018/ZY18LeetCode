//LeetCode 1300
//https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int ans = target / arr.size(), pre = INT_MAX, sum = 0;
        while(true){
            for(auto x : arr)
				sum += min(ans, x);
            if(sum == target)
				break;
            if (abs(sum-target) >= abs(pre-target)){
				--ans;
				break;
			}
            else{
                pre = sum;
                sum = 0;
                ++ans;
            }
        }
        return ans;
    }
};


//LeetCode 34
//https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		if(!nums.size())
			return {-1, -1};
		int mid = 0, left = 0, right = nums.size() - 1;
		while(left < right){
			mid = (left + right) / 2;
			if(nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if(nums[left] != target)
			return {-1, -1};
		right = left;
		while(right < nums.size() && nums[right] == target)
			++right;
		return {left, right - 1};
    }
};
