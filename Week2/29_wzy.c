1.class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count=0;
        int temp=1;
        for(auto &x:flowerbed)
        {
            if(x==0) 
            {
                temp+=1;
            }
            else
            {
                count=count+(temp-1)/2;
                temp=0;
            }
            
        }
        count=count+temp/2;
        if(count>=n)
        return true;
        else
        return false;

    }
};

2.int getWinner(int* arr, int arrSize, int k){
int count=0;//»ñÊ¤´ÎÊý
int temp;
while(count<k)
{
    if(arr[0]>arr[1])
    {
        temp=arr[1];
        for(int i=1;i<arrSize-1;i++)
        {
           arr[i]=arr[i+1];
        }
        arr[arrSize-1]=temp;
        count+=1;
    }
    else
    {
        count=1;
        temp=arr[0];
        arr[0]=arr[1];
        for(int i=1;i<arrSize-1;i++)
        {
           arr[i]=arr[i+1];
        }
        arr[arrSize-1]=temp;
        
    }
}
printf("%d",arr[0]);



}

3.class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return{};
        vector<vector<int>> res;
        queue<TreeNode*> bfs;
        vector<int>temp;
        bfs.push(root);
        int nextlevel=0,remain=1;
        while(!bfs.empty())
        {
           TreeNode* curr=bfs.front();
           temp.push_back(curr->val);
           bfs.pop();
           remain--;
           if(curr->left)
           {
               bfs.push(curr->left);
               nextlevel++;
           }
           if(curr->right)
           {
               bfs.push(curr->right);
               nextlevel++;

           }
           if(remain==0)
           {
               res.push_back(temp);
               temp.clear();
               remain=nextlevel;
               nextlevel=0;
           }

        
        }
        return res;


    }
};


