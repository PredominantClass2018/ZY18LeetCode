1
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    if(flowerbedSize<1) return false;
    if(flowerbedSize==1 && flowerbed[0]==0) return true;
    if(n==0) return true;
	int i;
	int count=0; 
	for(i=0;i<flowerbedSize;i++)
	{
		if(flowerbed[i]==1 ) continue;
		if((i==0 || flowerbed[i-1]==0) && (i==flowerbedSize-1 || flowerbed[i+1]==0)) 
		{
			++count;
			flowerbed[i]=1;
			
		}
		if(count>=n) return true;
	}
	return false;
}



2
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
    queue[tail++]=root;
    *returnSize=0;
    while(head<tail){
        int size=(tail-head+MAXSIZE)%MAXSIZE;
        (*returnColumnSizes)[*returnSize]=size;
        res[*returnSize]=(int*)malloc(sizeof(int)*size);
        for(int i=0;i<size;i++){
            struct TreeNode*temp=queue[head++];
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


