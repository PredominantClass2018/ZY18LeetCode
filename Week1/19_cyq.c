
//问题1
bool threeConsecutiveOdds(int* arr, int arrSize) {
	for (int i = 0; i < arrSize - 2;) {
		if (arr[i++] % 2 == 1 && arr[i++] % 2 == 1 && arr[i++] % 2 == 1) return true;
	}
	return false;

}

//问题二
//解法一
int sumOddLengthSubarrays(int* arr, int arrSize) {
	int sum = 0;
	int sum0 = 0;
	for (int i = 0; i < arrSize; ++i) {
		sum0 = 0;
		for (int j = i; j < arrSize; ++j) {
			sum0 += arr[j];
			if ((j - i) % 2 == 0) sum += sum0;
		}
	}
	return sum;
}

//问题三

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
	int f[triangleSize][triangleSize];
	memset(f, 0, sizeof(f));
	f[0][0] = triangle[0][0];
	for (int i = 1; i < triangleSize; ++i) {
		f[i][0] = f[i - 1][0] + triangle[i][0];
		for (int j = 1; j < i; ++j) {
			f[i][j] = fmin(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
		}
		f[i][i] = f[i - 1][i - 1] + triangle[i][i];
	}
	int ret = f[triangleSize - 1][0];
	for (int i = 1; i < triangleSize; ++i) {
		ret = fmin(ret, f[triangleSize - 1][i]);
	}
	return ret;
}


