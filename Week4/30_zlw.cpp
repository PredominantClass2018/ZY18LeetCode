

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

class Solution {
public:
    Solution() = default;

public:
    //1401. 圆和矩形是否有重叠
    //https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        //注意：矩形与坐标轴平行 降低了题目难度

        //圆心在矩形中
        if (x_center <= x2 && x_center >= x1 && y_center >= y1 && y_center <= y2) return true;
        
        //如果圆心在矩形之外，分成两大类情况
        
        

        //一、圆心坐标在四条边的Ymin和Ymax之间或Xmin和Xmax之间
        if (x_center >= x1 && x_center <= x2) 
        {
            if ((y_center < y1 && y1 - y_center <= radius) || (y_center > y2&& y_center - y2 <= radius))
                return true;
            else return false;
        }
        else if (y_center >= y1 && y_center <= y2)
        {
            if ((x_center < x1 && x1 - x_center <= radius) || (x_center > x2&& x_center - x2 <= radius))
                return true;
            else return false;
        }
        else {
            //二、圆心坐标既不在Ymin和Ymax之间也不在Xmin和Xmax之间，这时候想象圆往外扩张，首先碰到的肯定是矩形的四个顶点
            
            if ( (pow((x_center - x1), 2)) + (pow((y_center - y1), 2)) <= radius * radius || (pow((x_center - x1), 2)) + (pow((y_center - y2), 2)) <= radius * radius
                || (pow((x_center - x2), 2)) + (pow((y_center - y1), 2)) <= radius * radius || (pow((x_center - x2), 2)) + (pow((y_center - y2), 2)) <= radius * radius)
            {
                return true;
            }
        }

        return false;

        
    }

    //704. 二分查找
    //https://leetcode-cn.com/problems/binary-search/
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if (len == 0) return -1;

        int left = 0;
        int right = len - 1;
        int mid = len  / 2;
        while (left <= right )
        {
            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
            if (target > nums[mid])
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
        }
     
        return -1;
    }

    //189. 旋转数组
    //https://leetcode-cn.com/problems/rotate-array/
    void rotate(vector<int>& nums, int k) {
        /*
         //------------------------------begin暴力法----------------------------
        int len = nums.size();
        k = k % len;
        if (!k || len <= 1) return;     //k==0直接返回

        //k != 0
        //原地算法，不开辟新数组
      
        int tmp1, tmp2;
        for (int i = 1; i <= k; ++i)
        {
            tmp1 = nums[0];
            tmp2 = nums[1];
            for (int j = 0; j < len; ++j)   //数组全体右移一个位置
            {
                nums[(j + 1) % len] = tmp1;
                tmp1 = tmp2;
                tmp2 = nums[(j + 2) % len];
                 
            }
        }
        //------------------------------end暴力法----------------------------
        */
        
        /*
        //------------------------------begin翻转法-------------------------
        int len = nums.size();
        k = k % len;
        if (!k || len <= 1) return;     //k==0直接返回
        this->reserving(nums, 0, len - 1);
        this->reserving(nums, 0, k - 1);
        this->reserving(nums, k, len - 1);
        // //------------------------------end翻转法-------------------------
        */

        //------------------------------begin 利用【每个数的新位置=（index + k） % nums.size()】----------------------------
        int len = nums.size();
        k = k % len;
        if (!k || len <= 1) return;     //k==0直接返回

        int count = 0;  //当count计数到len，则全部归位

        for (int start_index = 0; count < len; ++start_index)
        {
            int cur_index = start_index;
            int prev_val = nums[cur_index];
            do {
                int next_index = (cur_index + k) % len;
                int tmp_val = nums[next_index];
                nums[next_index] = prev_val;
                prev_val = tmp_val;

                cur_index = next_index;
                count++;
            } while (start_index != cur_index);
        }
        //------------------------------end 利用【每个数的新位置=（index + k） % nums.size()】----------------------------
        
    }
 private:
     void reserving(vector<int>&nums,int left,int right)    //left到right区间内进行翻转
     {
         int tmp;
         while (left < right)
         {
             tmp = nums[right];
             nums[right] = nums[left];
             nums[left] = tmp;
             left++;
             right--;
         }
     }

};

int main(void)
{
  
 

    Solution s = Solution();
    vector<int> nums{ -1,0,3,5,9,12 };
    cout << s.search(nums,2);
   
    return 0;
}