#include "stdio.h"

bool threeConsecutiveOdds(int* arr, int arrSize);
int sumOddLengthSubarrays(int* arr, int arrSize);
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize);
void main() {
}
int sumOddLengthSubarrays(int* arr, int arrSize) {
	int i, j, k;
	int sum=0;
	for (i = 0; i < arrSize; i++) {
		k = i;
		j = i - 1;
		while (1) {
			j++;
			sum = sum + arr[j];
			if (j == k) {
				k = k + 2;
				j = i - 1;
			}
			if (k >= arrSize) break;
		}
	}
	return sum;
}
bool threeConsecutiveOdds(int* arr, int arrSize) {
	int i, j;
	for (i = 0; i < arrSize - 2; i++) {
		for (j = i; j < i + 3; j++) {
			if (arr[j] % 2 == 0) {
				break;
			}
		}
		if (j == i + 3) return true;
	}
	return false;
}
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
	int i, j;

	int* dp;
	dp = malloc(triangleSize * sizeof(int));

	// 初始化最下面一排的dp数组
	for (i = 0; i < triangleColSize[triangleSize - 1]; i++) {
		dp[i] = triangle[triangleSize - 1][i];
	}

	for (i = triangleSize - 2; i >= 0; i--) {
		for (j = 0; j < triangleColSize[i]; j++) {
			int minNum;
			minNum = dp[j] < dp[j + 1] ? dp[j] : dp[j + 1];
			dp[j] = minNum + triangle[i][j];
		}
	}

	return dp[0];
}