bool threeConsecutiveOdds(int* arr, int arrSize){
    int flag = 0;
	int cnt = 0;
	for (int i = 0; i < arrSize; ++i) {
		if (arr[i] % 2) {
			flag = 1;
			cnt++;
		}
		else {
			flag = 0;
			cnt = 0;
		}
		if (cnt == 3) return true;
	}
	return false;
}

void fun() {
	
}