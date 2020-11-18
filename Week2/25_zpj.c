//种花问题

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i;
    int count = 0;
    for(i = 0; i < flowerbedSize;){
        if(flowerbed[i])
            i = i + 2;
        else{
                if ((i + 1) < flowerbedSize&& flowerbed[i+1])
                i = i + 3;
            else{
                flowerbed[i] = 1;
                count++;
            }
        }
    }
    return count>=n;
}

//找出数组游戏的赢家
int getWinner(int* arr, int arrSize, int k){
    int i = 0;
    int prev = arr[i];
    int count = 1;
    int curr;
    if(arr[i] < arr[i+1])
        prev = arr[i+1];
    if(k == 1)
        return prev;
    
    for(i = 2; i < arrSize; i++){
        curr = arr[i];
        if(prev > curr){
            count++;
            if(count == k)
                return prev;
        }
        else{
            count = 1;
            prev = curr;
        }
    }
    return prev;
}

//从上到下打印二叉树
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
