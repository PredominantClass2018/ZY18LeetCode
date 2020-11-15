bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
if(flowerbedSize < 1)  return false;
    if(flowerbedSize ==1 && flowerbed[0]==0) return true;
    int count=0;
    for(int i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==0)
        {
            if(i==0)
            {
                if(flowerbed[i+1]==0)
                {
                    count++;
                    flowerbed[i]=1;
                }   
            }
            else if(i==(flowerbedSize-1))
            {
                if(flowerbed[i-1]==0)
                {
                    count++;
                    flowerbed[i]=1;
                }
            }
            else if(flowerbed[i-1]==0 && flowerbed[i+1]==0)
            {
                count++;
                flowerbed[i]=1;
            }
        }
    }
    if(count>=n)
        return true;
    return false;
}




int getWinner(int* arr, int arrSize, int k){
    int count = 0;
    int i = 0;
    int j = 1;
    while (j < arrSize && count < k) {
        if (arr[i] > arr[j]) {
            count++;
        } else {
            i = j;
            count = 1;
        }
        j++;
    }
    return arr[i];
}



int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(root==NULL)
    {
        *returnSize=0;
        return NULL;
    }
    struct TreeNode* a[10000];
    int head=0,tail=0;
    int **res=(int**)malloc(sizeof(int*)*10000);
    int n;

    *returnColumnSizes=(int*)malloc(sizeof(int*)*10000);
    a[head]=root;
    *returnSize=0;
    tail++;
    while(head<tail)
    {
        int size=tail-head;
        (*returnColumnSizes)[*returnSize]=size;
        res[*returnSize]=(int*)malloc(sizeof(int)*size);

        for(n=0;n<size;n++)
        {
            struct TreeNode* r=a[head];
            res[*returnSize][n]=r->val;
            head++;
            if(r->left)
            {
                a[tail]=r->left;
                tail++;
            }
            if(r->right)
            {
                a[tail]=r->right;
                tail++;
            }
        }
       (*returnSize)++;
    }
    return res;
}
