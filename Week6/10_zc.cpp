#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // ���һ
        if (leftBorder == -2 || rightBorder == -2) return { -1, -1 };
        // �����
        if (rightBorder - leftBorder > 1) return { leftBorder + 1, rightBorder - 1 };
        // �����
        return { -1, -1 };
    }
private:
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2; // ��¼һ��rightBorderû�б���ֵ�����
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else { // Ѱ���ұ߽磬nums[middle] == target��ʱ�����left
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2; // ��¼һ��leftBorderû�б���ֵ�����
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // Ѱ����߽磬nums[middle] == target��ʱ�����right
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
            //�����쳣���
            if (size == 0)
                return 0;
            //����
            sort(arr.begin(), arr.end());
            for (int i = 0; i < size; ++i)
            {
                //�Ե�ǰĿ����target��size-i��Ԫ�ص���ӽ�ƽ������
                double t = (double)target / (size - i);
                int m = t;
                //��������
                if (t - m - 0.5 > 0)
                    ++m;
                //�����Сֵ���ڵ�ǰƽ��ֵ
                if (arr[i] >= m)
                    return m;
                else
                    //��������
                    target -= arr[i];
            }
            return arr[size - 1];
        }
};