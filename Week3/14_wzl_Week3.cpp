//5.最长回文子串 
char * longestPalindrome(char * s){
    int N = strlen(s), start = 0, len = 0;  
    for (int i = 0; i < N; i++) {  
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right]){
            left--; right++;            
        }                              
        if (right - left - 1 > len) {  
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++) {  
        int left = i, right = i + 1;    
        while (left >=0 && right < N && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0';      
    return s + start;
}



//1025。除数博弈  
bool divisorGame(int N) {
    return N % 2 == 0;
}




//547.朋友圈c 
int fa[1000];
int find(int x){
        if(fa[x]==x) return x;
        return fa[x]=find(fa[x]);
    }
int findCircleNum(int** M, int MSize, int* MColSize){
    for(int i=0;i<MSize;i++)   fa[i]=i;
    int ans=MSize;
    for(int i=0;i<MSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(M[i][j]==0) continue;
            if(find(fa[i])!=find(fa[j]))
            {
                fa[find(i)]=fa[find(j)];
                ans--;
            }
        }
    }
    return ans;
}




