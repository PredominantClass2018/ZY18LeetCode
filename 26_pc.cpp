//1、种花问题
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;//计数种n朵花
        for (auto i = flowerbed.begin(); i != flowerbed.end(); ++i){
            if((*i) == 0 && (i == flowerbed.begin() || (*(i-1)) == 0) && (i == flowerbed.end()-1 || (*(i+1)) == 0)){
                (*i) = 1;
                count++;
            }
        }
        return n <= count;
    }
};

//2、找出数组游戏中的最大值
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner, i = 0;
        int n = arr.size();
        //两个特殊情况
        if (k == 1) return arr[0] > arr[1] ? arr[0] : arr[1];
;
        int prev = max(arr[0],arr[1]),temp = 0;
        int count = 1;//因为已经比较了一次
        for(i = 2; i < n; ++i){
            int curr = arr[i];//prev是第一次比较最大的  curr是要与prev比较的
            if(prev > curr){
                count++;
                if (count == k)
                    return prev;
            }
            else{
                prev = curr;//较大的数
                count = 1;
            }
            winner = max(prev,curr);
        }
        return winner;
    }
};

//3、从上到下打印二叉树
void BFS(struct TreeNode **queueArr, int start, int end, int* returnSize, int** returnColumnSizes, int **retArr)
{
    int i;
    int flagStart = start;
    int flagEnd = end;
    int levelNum = end - start;
    // 如果队列为空，则返回
    if (levelNum == 0) {
        return;
    }
    // 记录本层元素数量
    (*returnColumnSizes)[*returnSize] = levelNum;
    // 为本层返回数组申请内存
    retArr[*returnSize] = (int *)malloc(sizeof(int) * levelNum);
    // 填充该层返回数组内容
    for (i = 0; i < levelNum; i++) {
        retArr[*returnSize][i] = queueArr[start + i]->val;
    }
    // 层数++
    (*returnSize)++;
    // 将该层节点的子节点装入队列，注意判断子节点是否存在，该步也是广度优先遍历的重点
    for (i = flagStart; i < flagEnd; i++) {
        if (queueArr[start]->left != NULL) {
            queueArr[end++] = queueArr[start]->left;

        } if (queueArr[start]->right != NULL) {
            queueArr[end++] = queueArr[start]->right;
        }
        start++;
    }
    // 继续遍历队列中的节点
    BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

    return;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    // 为返回数组申请内存
    int **retArr = (int **)malloc(sizeof(int *) * 10000);
    memset(retArr, 0, sizeof(int *) * 10000);
    // 为模拟队列的数组申请内存，要稍微大一点
    struct TreeNode *queueArr[10000] = { { 0 } };
    // 为储存返回组每一列大小的数组申请内存
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    // 将根节点放入队列
    queueArr[0] = root;
    // 用start和end下标模拟进队出队
    int start = 0;
    int end = 1;
    // 广度优先遍历
    BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

    return retArr;
}

