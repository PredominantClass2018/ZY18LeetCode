bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int flow[flowerbedSize+2];
    int i=0;
    int j=0;
    flow[0]=flow[flowerbedSize+1]=0;
    memcpy(&flow[1],flowerbed,flowerbedSize*sizeof(int));
    for(i=1;i<=flowerbedSize;i++)
    {
        if(flow[i-1]==0&&flow[i]==0&&flow[i+1]==0)
        {
            j++;
            flow[i]=1;
        }
    }

    if(j>=n)
    return true;
    else
    return false;
}




int getWinner(int* arr, int arrSize, int k) {
    int* f, * s;
    int i, j = 1, m, n = 0;
    f = arr;
    s = arr + 1;
    while (s < arr + arrSize)
    {
        if (*f > * s) {
            n++;
            s = s + 1;
        }
        else {
            f = s;
            s = s + 1;
            n = 1;
        }
        if (n == k)
            break;
    }
    return *f;
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
