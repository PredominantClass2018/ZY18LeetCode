605. 种花问题
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
     int i,j,k=0;
     if(flowerbedSize==1&&flowerbed[0]==0) k=1;
     if(flowerbedSize==1&&flowerbed[0]==1) k=0;
     if(flowerbedSize==2) 
     {
         if(flowerbed[0]==0&&flowerbed[1]==0) k=1;
         else k=0;
     }
    if(flowerbedSize>2)
    {
     if(flowerbed[0]==0)
     {
        if(flowerbed[1]==0) 
		{
		flowerbed[0]=1;
	    k+=1;
		}
	 }
	 for(i=1;i<=flowerbedSize-2;i++)
     {
     	if(flowerbed[i-1]==0)
     	{
     	  if(flowerbed[i+1]==0)
		   {
		   	  if(flowerbed[i]==0)
		   	  {
		   		flowerbed[i]=1;
		   		k+=1;
			  }
			}  
		 }
	 }
         if(flowerbed[flowerbedSize-1]==0)
     {
        if(flowerbed[flowerbedSize-2]==0) 
		{
		flowerbed[flowerbedSize-1]=1;
	    k+=1;
		}
	 }
    }

     if(k>=n) return 1;
     else     return 0;
}
1535. 找出数组游戏的赢家
int getWinner(int* arr, int arrSize, int k){
	int i=0,j=1,count;
	while(j<arrSize&&count<k)
	{
		if(arr[i]>arr[j])
		{
			count++;
			j++;
		}
		else
		{
			i=j;
			j++;
			count=1;
		}
	}
	return arr[i];
}
剑指 Offer 32 - II. 从上到下打印二叉树 II
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    if(!root)
    {
        int **result=(int **)malloc(sizeof(int *)*1);
        *returnSize = 0;
        return result;
    }

    int **result = (int **)malloc(sizeof(int*) * 1000);
    struct TreeNode* queue[1500],* t;
    int level = 0;
    int rear = 0,front = 0,retSize = 0;
    queue[rear++] = root;
    while(front != rear){
        (*returnColumnSizes)[level] = rear - front;
        result[level] = (int *)malloc(sizeof(int) * (rear - front));
        for(int i = 0;i < (*returnColumnSizes)[level];i++){
            t = queue[front];
            result[level][i] = t->val;
            front++;
            if(t->left){
                queue[rear++] = t->left;
            }
            if(t->right){
                queue[rear++] = t->right;
            }
        }
        level++;
    }
    *returnSize = level;
    return result;
}

