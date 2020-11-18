//1���ֻ�����
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;//������n�仨
        for (auto i = flowerbed.begin(); i != flowerbed.end(); ++i){
            if((*i) == 0 && (i == flowerbed.begin() || (*(i-1)) == 0) && (i == flowerbed.end()-1 || (*(i+1)) == 0)){
                (*i) = 1;
                count++;
            }
        }
        return n <= count;
    }
};

//2���ҳ�������Ϸ�е����ֵ
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int winner, i = 0;
        int n = arr.size();
        //�����������
        if (k == 1) return arr[0] > arr[1] ? arr[0] : arr[1];
;
        int prev = max(arr[0],arr[1]),temp = 0;
        int count = 1;//��Ϊ�Ѿ��Ƚ���һ��
        for(i = 2; i < n; ++i){
            int curr = arr[i];//prev�ǵ�һ�αȽ�����  curr��Ҫ��prev�Ƚϵ�
            if(prev > curr){
                count++;
                if (count == k)
                    return prev;
            }
            else{
                prev = curr;//�ϴ����
                count = 1;
            }
            winner = max(prev,curr);
        }
        return winner;
    }
};

//3�����ϵ��´�ӡ������
void BFS(struct TreeNode **queueArr, int start, int end, int* returnSize, int** returnColumnSizes, int **retArr)
{
    int i;
    int flagStart = start;
    int flagEnd = end;
    int levelNum = end - start;
    // �������Ϊ�գ��򷵻�
    if (levelNum == 0) {
        return;
    }
    // ��¼����Ԫ������
    (*returnColumnSizes)[*returnSize] = levelNum;
    // Ϊ���㷵�����������ڴ�
    retArr[*returnSize] = (int *)malloc(sizeof(int) * levelNum);
    // ���ò㷵����������
    for (i = 0; i < levelNum; i++) {
        retArr[*returnSize][i] = queueArr[start + i]->val;
    }
    // ����++
    (*returnSize)++;
    // ���ò�ڵ���ӽڵ�װ����У�ע���ж��ӽڵ��Ƿ���ڣ��ò�Ҳ�ǹ�����ȱ������ص�
    for (i = flagStart; i < flagEnd; i++) {
        if (queueArr[start]->left != NULL) {
            queueArr[end++] = queueArr[start]->left;

        } if (queueArr[start]->right != NULL) {
            queueArr[end++] = queueArr[start]->right;
        }
        start++;
    }
    // �������������еĽڵ�
    BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

    return;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    // Ϊ�������������ڴ�
    int **retArr = (int **)malloc(sizeof(int *) * 10000);
    memset(retArr, 0, sizeof(int *) * 10000);
    // Ϊģ����е����������ڴ棬Ҫ��΢��һ��
    struct TreeNode *queueArr[10000] = { { 0 } };
    // Ϊ���淵����ÿһ�д�С�����������ڴ�
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10000);
    // �����ڵ�������
    queueArr[0] = root;
    // ��start��end�±�ģ����ӳ���
    int start = 0;
    int end = 1;
    // ������ȱ���
    BFS(queueArr, start, end, returnSize, returnColumnSizes, retArr);

    return retArr;
}

