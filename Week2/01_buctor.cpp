class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int k) {
        int n = flowerbed.size();
        int cnt = 0;
        for(int i = 0,pre = 0; i < n; i++){
            if(flowerbed[i]==1){
                pre = 1;
            }else{
                if(pre==1){
                    pre = 0;
                }else{
                    if(i+1<n){
                        if(flowerbed[i+1]==0){
                            cnt++;
                            pre = 1;
                        }
                    }else{
                        cnt++;
                    }
                }
            }
        }
        if(cnt >= k) return true;
        else return false;

    }
};

const int N = 1e6 + 10;
int f[N];
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        memset(f,0,sizeof(int)*N);
        if(k>=arr.size()-1){
            //return max
            sort(arr.begin(),arr.end());
            return arr[arr.size()-1];
        }
        for(int i = 0, j =1; i < arr.size();){
            while(j < arr.size() && arr[j] < arr[i]){
                f[arr[i]]++;
                j++;
            }
            if(j==arr.size()){
                return arr[i];
            }else{
                f[arr[j]]++;
            }
            if(f[arr[i]]>=k) return arr[i];
            i = j;
            j = i + 1;
        }
        return 0;
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
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        while(q.size()){
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; i++){
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
