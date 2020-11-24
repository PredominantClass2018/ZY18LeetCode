char * longestPalindrome(char * s){
    int left = 0;
    int right = 0;    
    int maxLength = 0;      
    int startIndex = 0;     
    int index = 0;

    while(s[index]){
        right=index;
        left=index-1;
        while(s[right]==s[index]){
            right++;
        }
        index = right;
        while(left >= 0 && s[right] && s[left]==s[right]){
            left--;
            right++;
        }
        if(right-left-1>maxLength){
            startIndex = left+1;
            maxLength = right-left-1;
        }
     
    }
    char* returnStr = (char*)malloc(maxLength+1);
    returnStr[maxLength]='\0';
    for(int i=0;i<maxLength;i++){
        returnStr[i]=s[startIndex+i];
    }
    return returnStr;
}




bool divisorGame(int N){
    if(N%2) return false;
    else return true;
}


void dfs(int** M, int i, int j, int MSize, int* MColSize) {
    M[i][j] = 0;
    for (int m = j; m < MSize; m++) {
        if (M[m][j] == 1) {
            dfs(M, m, j, MSize, MColSize);
        }
    }
    for (int n = 0; n < i + 1; n++) {
        if (M[i][n] == 1) {
            dfs(M, i, n, MSize, MColSize);
        }
    }
    return;
}
int findCircleNum(int** M, int MSize, int* MColSize){
    if (M == NULL || MSize == 0) {
        return 0;
    }
    int num = 0;
    for (int i = 0; i < MSize; i++) {
        for (int j = 0; j < i + 1; j++) {
            if (M[i][j] == 1) {
                num++;
                dfs(M, i, j, MSize, MColSize);
            }
        }
    }
    return num;
}
