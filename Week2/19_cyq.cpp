bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int sum=0;
    int count=1;
    for(int i=0;i<flowerbedSize;++i){
        if(flowerbed[i]==1){
            sum+=(count-1)/2;
            count=0;
        }
        else count++;
    }
    if(count!=0) sum+=(count)/2;
    if(sum>=n) return true;
    else return false;
}

int getWinner(int* arr, int arrSize, int k){
    int  max=arr[0];
    int count=0;
    for(int i=1;i<arrSize;++i){
        if(max<arr[i]){
            max=arr[i];
            count=1;
        }
        else ++count;
        if(count>=k) break;
    }
    return max;
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root,res,0);
        return res;
    }
    void dfs(TreeNode* root,vector<vector<int>>& res,int level)
    {
        if(!root) return;
        if(level>=res.size()) res.emplace_back(vector<int>());
        res[level].emplace_back(root->val);
        dfs(root->left,res,level+1);
        dfs(root->right,res,level+1);
    }
};
