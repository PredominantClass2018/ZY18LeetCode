//5

#include"string.h"

char * longestPalindrome(char * s){
   
    /*int N=strlen(s);
    int start=0,len=0;
    for(int i=0;i<N;i++)
    {
        int left=i-1,right=i+1;
        while(left>=0&&right<N&&s[left]==s[right])
        {
            left--;
            right++;
        }
        if(right-left-1>len)
        {
            start=left+1;
            len=right-left-1;
        }
    }

    for(int i=0;i<N;i++)
    {
        int left=i,right=i+1;
        while(left>=0&&right<N&&s[left]==s[right])
        {
            left--;
            right++;
        }
        if(right-left-1>len)
        {
            start=left+1;
            len=right-left-1;
        }
    }
    s[start+len]='\0';
    return s+start;
    */
   int right = 0, left = 0, count = 0;
    int startidx = 0;
    int max_len = 0;
    for (int i = 0; s[i] != '\0'; i += count) {
        count = 1;
        left = i - 1;
        right = i + 1;

        while ((s[right]!='\0') && (s[i] == s[right])) { // 选出重复字符
            right++;
            count++;
        }
        
        while ((left >= 0) && (s[right]!='\0') && (s[left] == s[right])) { // 由中心字符向左右扩展
            left--;
            right++;
        }
        
        if (max_len < (right - left - 1)) {
            max_len = right - left - 1;  // 左右标记不在回文子串范围内，在外面两侧，需要减1
            startidx = left + 1;
        }
    }
    s[startidx + max_len] = '\0';
    return s + startidx;


}




//1025

bool divisorGame(int N){
    /*
    if(N%2==0)
    return true;
    else
    return false;
    */
    int f[N+5];
    memset(f,0,sizeof(f));
    f[1]=false;
    f[2]=true;
    for(int i=3;i<=N;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(i%j==0&&!f[i-j])
            {
                f[i]=true;
                break;
            }
        }
    }
    return f[N];
}





//547

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