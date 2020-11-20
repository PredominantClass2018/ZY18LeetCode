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
//����ֻ��Ҫ�жϸ�λ�ǲ���0��Ȼ���ж��±���0����ǰһλ��0�����ж��±��ǳ��ȼ�һ���Ǻ�һλ��0
//3������ȱһ����


//1535   �����Լ�д�Ĵ������һ��ʵ����ʾ����ʱ�����ƣ����Կ��ý���
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
        TreeNode* b;//����ָ��ǰ���е���Ԫ��
        if(!root) return {};
        vector<vector<int>>res;//��̬����  һ��Ԫ�������Ӧ������Ԫ��
        vector<int>temp;//����ÿһ���Ԫ��
        queue<TreeNode*> a;//����   ���浱ǰ���Ԫ��
        a.push(root);//���������������
        int num=0,nums=1;//nums��¼��ǰ��ʣ��Ԫ�ظ���   num��¼��һ��Ԫ�ظ���
        while(!a.empty()){
            b=a.front();//��bָ����е���Ԫ�ص�ַ
            temp.push_back(b->val);//����Ӧλ�õ�ֵ���뵽temp��
            a.pop();//��Ԫ�ط��뵽�����к󣬵�������
            nums--; // temp��ÿ���һ����ǰ��Ԫ��   nums--
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