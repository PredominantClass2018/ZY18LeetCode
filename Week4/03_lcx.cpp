//LeetCode 1401
//https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/submissions/
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x = 0, y = 0;

        if(x_center > x2)
			x = x2;
        else if(x_center < x1)
			x = x1;
        else
			x = x_center;
        if(y_center > y2)
			y = y2;
        else if(y_center < y1)
			y = y1;
        else
			y = y_center;
        return ((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center)) <= (radius * radius);
    }
};

//LeetCode 704
//https://leetcode-cn.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(left <= right){
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return -1;
    }
};

//LeetCode 189
//https://leetcode-cn.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());

        return;
    }
};

