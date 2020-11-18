/*
Auhor:Longwu Zhu
Date:2020/11/11
Description:卓越班第二周刷题
*/

#include<iostream>
#include<vector>
#include<queue>
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
 
    //605.种花问题
    //https://leetcode-cn.com/problems/can-place-flowers/
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        //flowerbed = [1,0,0,0,1], n = 1
        if (n == 0)
            return true;

        for (int i = 0; i < flowerbed.size();)
        {
            if (flowerbed[i] == 1)
            {
                //扫描到1，则右位置不能用了，i+=2
                i += 2;
                continue;
            }
            if (flowerbed[i] == 0)
            {
                //扫描到0，如果右边也是0则可以种下(从左向右扫描，默认左边为0)
                if (i+1 == flowerbed.size() || flowerbed[i + 1] == 0)
                {
                    //flowerbed[i] = 1,在当前位置可以种下
                    --n;
                    i += 2;

                }
                else
                    i += 3;
            }
        }


        if (n > 0) 
            return false;
        return true;
    }

    //1535.找出数组游戏中的玩家
    //https://leetcode-cn.com/problems/find-the-winner-of-an-array-game/
        int getWinner(vector<int>& arr, int k) {

           //输入：arr = [2,1,3,5,4,,7], k = 2

            int length = arr.size();
       
        
            int i = 0,j = 1; //数组下标
            int c = 0;      //累胜次数
            while(1)  
            {
            
                if (arr[i] > arr[j])
                {
                    ++c;    //累胜次数+1
                    if (c == k)
                        return arr[i];
                    ++j;    //j指向下一个，i不变
                }
                else if (i == j)
                {
                    ++j;        //j绕一圈会和i重合，若重合j就跳过i
                }
                else
                {
                    //arr[i] < arr[j]
                    i = j;  //i指向的位置默认为较大数
                    ++j;    //j指向下一个，进行下一回合比较
                    c = 1;  //某个数胜利的第一回合
                }

                j = j % length;
            }
        }

        //剑指 Offer 32 - II. 从上到下打印二叉树 II
        //https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
        vector<vector<int>> levelOrder(TreeNode* root) {
            
            vector<vector<int>> result;

            if (root == NULL)
                return result;

            queue<TreeNode*>q;
            vector<int>tmp;
            TreeNode* tn;
            q.push(root);
            while (!q.empty())
            {
                for (int i = q.size(); i > 0; --i)
                {
                    tn = q.front();
                    q.pop();
                    tmp.push_back(tn->val);
                    if (tn->left != NULL)
                        q.push(tn->left);
                    if (tn->right != NULL)
                        q.push(tn->right);
                }
                result.push_back(tmp);
                tmp.clear();
            }
            
            return result;
        }
    
    };

int main(void)
{
   
    //2147483647
    //1000000000
    Solution s = Solution();
    vector<int>W = vector<int>{ 1,11,22,33,44,55,66,77,88,99 };
    //cout<<s.getWinner(W, 1000000000);
    

    return 0;
}