//605
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum=0;
        for(int i=0;i<flowerbed.size();++i){
            if ((flowerbed[i] == 0) && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                 sum++;
            }
        }
        return sum>=n;
    }
};
//我们只需要判断该位是不是0，然后判断下标是0还是前一位是0，在判断下标是长度减一还是后一位是0
//3个条件缺一不可


//1535   由于自己写的代码最后一个实例显示超出时间限制，所以看得解析
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int num = 0;
        int m=0;
        for(int i=1;i<arr.size();i++){
            m++;
            if(arr.at(i) < arr.at(0)) {
                num ++;
            }
            else{
                if(num >= k) break;
                num = 1;
                arr.at(0) = arr.at(i);
            }
            if(m==arr.size()-1) break;
        }
        return arr.at(0);
    }
};


//32-2
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
        TreeNode* b;//用来指向当前队列的首元素
        if(!root) return {};
        vector<vector<int>>res;//动态数组  一个元素里面对应层数的元素
        vector<int>temp;//保存每一层的元素
        queue<TreeNode*> a;//队列   保存当前层的元素
        a.push(root);//将根结点放入队列中
        int num=0,nums=1;//nums记录当前层剩余元素个数   num记录下一层元素个数
        while(!a.empty()){
            b=a.front();//将b指向队列的首元素地址
            temp.push_back(b->val);//将对应位置的值放入到temp中
            a.pop();//将元素放入到队列中后，弹出队列
            nums--; // temp中每添加一个当前层元素   nums--
            if(b->left!=NULL){
                a.push(b->left);
                num++;
            }
            if(b->right!=NULL){
                a.push(b->right);
                num++;
            }
            if(nums==0){
                res.push_back(temp);
                temp.clear();
                nums=num;
                num=0;
            }
        }
        return res;
    }
};