//1401
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x, y, r;
        x = (x1 + x2) / 2.0;
        y = (y1 + y2) / 2.0;
        r = sqrt((double)(x1 - x2) * (x1 - x2) + (double)(y1 - y2) * (y1 - y2)) / 2;
        double left, right, up, down;
        left = x1 - radius;
        right = x2 + radius;
        up = y2 + radius;
        down = y1 - radius;
        double dis = sqrt((double)(x - x_center) * (x - x_center) + (double)(y - y_center) * (y - y_center));
        if (dis > radius + r) {
            return false;
        }
        else if (x_center < left || x_center > right || y_center < down || y_center > up) {
            return false;
        }
        return true;
    }
};
//704
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (left == right && nums[left] == target) {
            return 0;
        }
        while (left <= right) {
            int t = (left + right) / 2;
            if (nums[t] == target) {
                return t;
            }
            else if (target > nums[t]) {
                left = t + 1;
            }
            else {
                right = t - 1;
            }
            if (right == left && nums[left] == target) {
                return left;
            }
        }
        return -1;
    }
};
//189
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);

    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};