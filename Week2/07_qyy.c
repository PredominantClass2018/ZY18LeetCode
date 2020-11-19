bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i,count=0;
    if(flowerbedSize==1)//长度为1
    {
        if(flowerbed[0]==0)
        {
            if(n<=1||n==0)
                return 1;
            else
                return 0;
        }
    }
    if(flowerbedSize==2)//长度为2
    {
        if(flowerbed[0]==0&&flowerbed[1]==1)
        {
            flowerbed[0]=1;
            if(n<=1||n==0)
                return 1;
            else
                return 0;
        }
    }
    //大于3
    if(flowerbed[0]==0&&flowerbed[1]==0)
    {
        flowerbed[0]=1;
        count++;
    }
    if(flowerbed[flowerbedSize-1]==0&&flowerbed[flowerbedSize-2]==0)
    {
        flowerbed[flowerbedSize-1]=1;
        count++;
    }
    for(i=2;i<flowerbedSize-1;i++)
    {
        if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
        {
            flowerbed[i]=1;
            count++;
        }
    }
    if(count>=n)
        return 1;
    else
        return 0;
}


int getWinner(int* arr, int arrSize, int k){
    int i,temp,count=0;
    for(i=1;i<arrSize;i++)
    {
        if(arr[0]>arr[i])
        {
            count++;
            if(count==k)
                break;
        }
        else
        {
            arr[0]=arr[i];
            count=1;
            if(count==k)
                break;
        }
    }
    return arr[0];
}


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
