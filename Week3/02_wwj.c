

/*5最长回文子串*/

char * longestPalindrome(char * s){
    if(strlen(s)==0||strlen(s)==1) return s;
    int i,start,left,right,count,len;
    start = len =0;
    for(i=0;s[i]!='\0';i+=count){
        count = 1;
        left=i-1;
        right = i+1;
        while(s[right]!='\0'&&s[i]==s[right]){ 
            right++;
            count++;
        }
        while(left>=0 && s[right]!='\0' && s[left] == s[right]){
            left--;
            right++;
        }
        if(right-left-1>len){
            start = left+1;
            len = right-left-1;
        }
    }
    s[start + len] = '\0';    
    return s + start;
}

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


