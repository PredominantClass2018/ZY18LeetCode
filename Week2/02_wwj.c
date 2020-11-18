

/*605种花问题*/

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i;
    if(n==0) return true;
    if(flowerbedSize==1&&flowerbed[0]==0)
    {
       return true;
    }
    for(i=0;i<flowerbedSize;i++)
    {
        if(flowerbed[i]==0&&((i==0&&flowerbed[i+1]==0)||(i==flowerbedSize-1&&flowerbed[i-1]==0)||((i>0&&i<flowerbedSize-1)&&flowerbed[i-1]==0&&flowerbed[i+1]==0)))
        {
            n--;flowerbed[i]=1;
            if(n==0) return true;
        }
    }
    return false;
}

/*1535找出数组游戏的赢家*/
int getWinner(int* arr, int arrSize, int k){
    int times = 0;
    int i = 0;
    int j = 1;
    while (j < arrSize && times < k) {
        if (arr[i] > arr[j]) {
            times++;
        } else {
            i = j;
            times = 1;
        }
        j++;
    }
    return arr[i];
}
	
/*从上到下打印二叉树*/

 int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int *nums = (int *)malloc(sizeof(int) * 10000);
    int **res = (int **)malloc(sizeof(int *) * 1000);
    returnColumnSizes[0] = (int *)malloc(sizeof(int) * 1000);
    returnSize[0] = 0;
    struct TreeNode *Queue[10000];
    int front, rear, last, cnt, n;
    front = rear = last = cnt = n = 0;
    Queue[root? rear++: rear] = root;
    last = rear;

    while (front < rear) {
        struct TreeNode *p = Queue[front++];
        ++cnt;
        nums[n++] = p->val;
        if (p->left) Queue[rear++] = p->left;
        if (p->right) Queue[rear++] = p->right;

        if (front == last) {
            last = rear;
            returnColumnSizes[0][returnSize[0]] = cnt;
            res[returnSize[0]++] = nums + n - cnt;
            cnt = 0;
        }
    }

    return res;
}


