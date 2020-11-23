

/*5最长回文子串*/

null 

/*1025除数博弈*/
bool divisorGame(int N){
   return N%2==0;
}
	
/*547朋友圈*/

 void dfs(int** M, int MColSize, int* visit, int index) {
    for (int i = 0; i < MColSize; i++) {
        if (M[index][i] == 1 && visit[i] == 0) {
            visit[i] = 1;
            dfs(M, MColSize, visit, i);
        }
    }
    return;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int cnt = 0;
    int* visit = (int*)calloc(MSize, sizeof(int));
    for (int i = 0; i < MSize; i++) {
        if (visit[i] == 0) {
            cnt++;
            dfs(M, MColSize[i], visit, i);
        }
    }
    return cnt;
}


