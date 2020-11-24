class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
       int size = flowerbed.size();
        int cnt = 0;
        for(int i = 0 ; i < size ; i++) {
            if(!flowerbed[i] && (!flowerbed[max(0 , i - 1)] && 
               !flowerbed[min(size - 1 , i + 1)])) {
                flowerbed[i] = 1;
                cnt++;
            }
        }
        return cnt >= n;
    }
};
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n = arr.size(), i = 1, ans = arr[0], t=k;
        while(t-- && i < n)//模拟k次
        {
            if(ans < arr[i])//碰见比我大的
            {
                ans = arr[i];//更改答案
                t = k-1;//该大数，还要模拟k-1次
            }
            i++;
        }
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)     return ans;
        queue<TreeNode*> myQue;
        myQue.push(root);
        while(!myQue.empty()){
            vector<int> tmp;
            int size = myQue.size();
            for(;size--;myQue.pop()){
                auto node = myQue.front();
                if(node->left)      myQue.push(node->left);
                if(node->right)     myQue.push(node->right);               
                tmp.push_back(node->val);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};