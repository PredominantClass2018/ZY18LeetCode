/*
Auhor:Longwu Zhu
Date:2020/11/
Description:卓越班第一周刷题
*/

#include<iostream>
#include<vector>

using namespace std;

//1588. 所有奇数长度子数组的和
class Solution {
public:
    Solution() = default;

public:
    /*
        1588. 所有奇数长度子数组的和
        https://leetcode-cn.com/problems/sum-of-all-odd-length-subarrays/
    */
    int sumOddLengthSubarrays(vector<int>& arr) {
        int length = arr.size();    //给定数组的元素数量
        if (length == 0) return 0;
        int sum = 0;
        for (int i = 0; i < length; ++i)
        {
            sum += arr[i];
            for (int j = 2; j < length - i; j += 2)
            {
                for (int k = i; k <= i + j; ++k)  sum += arr[k];
            }
        }

        return sum;
    }

    /*  
        1550. 存在连续三个奇数的数组
        https://leetcode-cn.com/problems/three-consecutive-odds/
    */
    bool threeConsecutiveOdds(vector<int>& arr) {
        int length = arr.size();
        if (length < 3) return false;

        int c = 0;  //连续奇数的个数
        for (int i = 0; i < length; ++i)
        {
            if (arr[i] % 2 == 0)
            {
                c = 0;
                continue;
            }
            else
            {
                ++c;
                if (c == 3)
                    return true;
            }

        }
        return false;
    } 

    /*
        120. 三角形最小路径和
        https://leetcode-cn.com/problems/triangle/
    */
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        if (length == 0) return 0;

        int sum = 0;
        int last_index = 0; //记录上一层的下标（初始化为第一层的下标）
        for (int i = 1; i < length; ++i)    //从第二层开始算，第一层留到最后加上去
        {
            sum += (triangle[i][last_index] < triangle[i][last_index + 1] ? triangle[i][last_index] : triangle[i][last_index + 1]);
            //更新上一层的下标
            last_index = ( triangle[i][last_index] < triangle[i][last_index + 1] ? last_index : last_index + 1 );   
        }

        return sum+triangle[0][0];  //记得加上第一层的数
    }
};

int main(void)
{
    Solution s = Solution();

    vector<vector<int>> vecs = vector<vector<int>>({ {-1},{2,3},{1,-1,-3} });
    cout << s.minimumTotal(vecs)<< endl;
}