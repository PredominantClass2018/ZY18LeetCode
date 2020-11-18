#include "stdio.h"
#include "stdlib.h"


struct TreeNode {
      int val;
     struct TreeNode *left;
      struct TreeNode *right;
};
 


bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);
int getWinner(int* arr, int arrSize, int k);
int main() {
	int flowerbed[10] = { 1,11,22,33,44,55,66,77,88,99 };
	int z = getWinner(flowerbed, 10, 1000000000);
	printf("%d", z);
}
bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
	int count = 0, i;
	
		for (i = 0; i < flowerbedSize; i++) {
			if (flowerbedSize == 1 && flowerbed[0] == 0) {
				flowerbed[0] = 1;
				count++;
			}else if (i == 0 && flowerbed[i]==0 && flowerbed[i + 1]==0) {
				flowerbed[i] = 1;
				count++;
			}
			else if (i > 0 && i < flowerbedSize-1 && flowerbed[i - 1] != 1 && flowerbed[i + 1] != 1 && flowerbed[i] != 1){
					flowerbed[i] = 1;
					count++;
				}
			else if (i == flowerbedSize - 1 && flowerbed[i] != 1 && flowerbed[i - 1] != 1) {
				flowerbed[flowerbedSize - 1] = 1;
				count++;
			}
			if (count >= n) return true;
			else        return false;
		}
		
}
int getWinner(int* arr, int arrSize, int k) {
	int Lcurrent = 0;
	int LCnumber = 0;
	int Maxnumber = 0;
	int C;
 	int compare = 1;
	if (k >= arrSize - 1) {
		int k, max = arr[0];
		for (k = 1; k < arrSize; ++k) {
			if (arr[k] > max) {
				max = arr[k];
			}
		}
		return max;
	}
	while (LCnumber != k) {
		if (compare == arrSize) compare = 0;
		if (compare != Lcurrent) {
			if (arr[Lcurrent] > arr[compare]) {
				LCnumber++;
				//compare++;
			}else{
				LCnumber = 1;
				C = Lcurrent;
				Lcurrent = compare;
				//compare++;
			}
		}
		compare++;
	}
	return arr[Lcurrent];
}
#define MAXSIZE 10000

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	struct TreeNode* queue[MAXSIZE] = { 0 };
	int head = 0, tail = 0;
	int** res = (int**)malloc(sizeof(int*) * MAXSIZE);
	*returnColumnSizes = (int*)malloc(sizeof(int*) * MAXSIZE);
	queue[tail++] = root;//push
	*returnSize = 0;
	while (head < tail) {
		int size = (tail - head + MAXSIZE) % MAXSIZE;
		(*returnColumnSizes)[*returnSize] = size;
		res[*returnSize] = (int*)malloc(sizeof(int) * size);
		for (int i = 0; i < size; i++) {
			struct TreeNode* temp = queue[head++];//pop
			res[*returnSize][i] = temp->val;
			if (temp->left) {
				queue[tail++] = temp->left;
			}
			if (temp->right) {
				queue[tail++] = temp->right;
			}
		}
		(*returnSize)++;
	}
	return res;
}