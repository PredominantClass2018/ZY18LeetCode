5. 最长回文子串
char * longestPalindrome(char * s){
    int N = strlen(s), start = 0, len = 0;  // N 字符串长度， start 子串起始位置， len 子串长度
    for (int i = 0; i < N; i++) {   // 奇数长度的回文子串
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right]){
            left--; right++;            // 以 i 为中心，向两侧延伸，直到不再满足回文
        }                               // left+1 ~ right-1 则为以i为中心的最大回文子串
        if (right - left - 1 > len) {   // 若更长，则保存该子串信息
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++) {   // 偶数长度的回文子串
        int left = i, right = i + 1;    // 以 i+0.5 为中心，向两侧延伸
        while (left >=0 && right < N && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0';      // 原地修改返回
    return s + start;
}

547. 朋友圈
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

1025. 除数博弈
bool divisorGame(int N){
    if(N%2==0)
    return true;
    else  
    return false;
}




