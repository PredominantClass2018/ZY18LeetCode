#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
        // 情况三
        if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
        // 情况二
        return { -1, -1 };
    }
private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else { // 寻找右边界，nums[middle] == target的时候更新left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            }
            else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};
class Solution {
public:
    int check(const vector<int>& arr, int x) {
        int ret = 0;
        for (const int& num : arr) {
            ret += (num >= x ? x : num);
        }
        return ret;
    }

    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> prefix(n + 1);
        for (int i = 1; i <= n; ++i) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        int l = 0, r = *max_element(arr.begin(), arr.end()), ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            auto iter = lower_bound(arr.begin(), arr.end(), mid);
            int cur = prefix[iter - arr.begin()] + (arr.end() - iter) * mid;
            if (cur <= target) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        int choose_small = check(arr, ans);
        int choose_big = check(arr, ans + 1);
        return abs(choose_small - target) <= abs(choose_big - target) ? ans : ans + 1;
    }
};
    class Solution {
    public:
        int findBestValue(vector<int>& arr, int target) {
            int size = arr.size();
            //输入异常情况
            if (size == 0)
                return 0;
            //排序
            sort(arr.begin(), arr.end());
            for (int i = 0; i < size; ++i)
            {
                //对当前目标数target求size-i个元素的最接近平均整数
                double t = (double)target / (size - i);
                int m = t;
                //四舍五入
                if (t - m - 0.5 > 0)
                    ++m;
                //如果最小值大于当前平均值
                if (arr[i] >= m)
                    return m;
                else
                    //更新数据
                    target -= arr[i];
            }
            return arr[size - 1];
        }
};