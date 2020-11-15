//605（种花问题）

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n)
{
    /*int i;
    for(i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i-1>=0?i-1:i]==0&&flowerbed[i+1<flowerbedSize?i+1:i]==0&&flowerbed[i]==0)
        {
            n--;
            flowerbed[i]=1;
        }
    }
    if(n>0) return false;
    else return true;
    */
    int count=0,i;
    if(flowerbedSize==1&&flowerbed[0]==0)
    count++;
    else if(flowerbedSize==2)
    {
        if(flowerbed[0]==0&&flowerbed[1]==0) 
        count++;
    }
    else
    {
        for(int i=0;i<flowerbedSize;i++)
        {
            if(i==0)
            {    
                if(flowerbed[i]==0&&flowerbed[i+1]==0)
                {
                    count++;
                    flowerbed[i]=1;
                } 
            }else if(i==flowerbedSize-1)
            {
                if(flowerbed[i]==0&&flowerbed[i-1]==0)
                {
                    count++;
                    flowerbed[i]=1;
                } 
            }
            else
            {
                if(flowerbed[i]==0)
                {
                    if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
                    {
                        count++;
                        flowerbed[i]=1;
                    }
                }
            }
        }
    }
    if(count>=n) return true;
    else return false;
}



//1535（数组中最大值）

int getWinner(int* arr, int arrSize, int k)
{
    int win=arr[0],count=0,i;
    for(i=1;i<arrSize&&count<k;i++)
    {
        if(arr[i]<win)
        count++;
        else
        {
            win=arr[i];
            count=1;
        }
    }
    return win;
}



//offer 32-II

#define MAXSIZE 10000
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
     if(root==NULL){
        *returnSize=0;
        return NULL;
    }
    struct TreeNode*queue[MAXSIZE]={0};
    int head=0,tail=0;
    int **res=(int**)malloc(sizeof(int*)*MAXSIZE);
    *returnColumnSizes=(int*)malloc(sizeof(int*)*MAXSIZE);
    queue[tail++]=root;//push
    *returnSize=0;
    while(head<tail){
        int size=(tail-head+MAXSIZE)%MAXSIZE;
        (*returnColumnSizes)[*returnSize]=size;
        res[*returnSize]=(int*)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++){
            struct TreeNode*temp=queue[head++];//pop
            res[*returnSize][i]=temp->val;
            if(temp->left){
                queue[tail++]=temp->left;
            }
            if(temp->right){
                queue[tail++]=temp->right;
            }
        }
        (*returnSize)++;
    }
    return res;
}
