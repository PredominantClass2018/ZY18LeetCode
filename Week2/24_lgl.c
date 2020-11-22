1 
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int flag=0;
    int i;
    if(flowerbedSize==1&&flowerbed[0]==0)
    {
        flag+=1;
    }
    else{
        for(i=0;i<flowerbedSize;i++)
        {
            if(flowerbed[i]==0)
            {
                if(i==0)
                {
                    if(flowerbed[1]==0)
                    {
                        flag+=1;
                        flowerbed[i]=1;
                    }
                }
                else if(i==flowerbedSize-1)
                {
                    if(flowerbed[flowerbedSize-2]==0)
                    {
                        flag+=1;
                        flowerbed[i]=1;
                    }
                }
                else if(flowerbed[i+1]==0&&flowerbed[i-1]==0)
                {
                    flag++;
                    flowerbed[i]=1;
                }
            }
        }
    }
    if(flag>=n)
    {
        return true;
    }
    else
        return false;
}

2
int getWinner(int* arr, int arrSize, int k){
    int p=0,win=arr[0];
    for (int i=1;i<arrSize;i++){
        if (arr[i]<win){
            p++;
            if (p==k){
                break;
            }
        }
        else {
            win=arr[i];
            p=1;
            if (p==k){
                break;
            }
        }
    }
    return win;
}

3
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
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
