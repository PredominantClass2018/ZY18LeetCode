#include "iostream"
#include "vector"
using namespace std;
//¶þ·Ö²éÕÒ
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int p = left + (right - left) / 2;
            if (nums[p] == target) return p;
            if (nums[p] > target) left = p + 1;
            else right = p - 1;
        }
        return -1;
    }
};
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x = 0.5 * (x1 + x2), y = 0.5 * (y1 + y2);
        double lenx = x2 - x1, leny = y2 - y1;
        double disx = abs(x_center - x);
        double disy = abs(y_center - y);
        double dis = max(disx - lenx / 2, 0.0) * max(disx - lenx / 2, 0.0) + max(disy - leny / 2, 0.0) * max(disy - leny / 2, 0.0);
        return dis <= radius * radius;
    }
};
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int* m = new int[n];
        k = k % n;
        int p = n - k - 1;
        int q = p+1;
        for (int i = 0; i < k; i++) {
            p++;
            m[i] = nums[p];
        }
        int j = 0;
        for (int i = k; i < n; i++) {
            
            if (j <  q) {
                m[i] = nums[j];
                j++;
            }
        }
        for (int i = 0; i < n; i++) {
            nums[i] = m[i];
        }
    }
};