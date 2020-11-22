char * longestPalindrome(char * s){
    if(strlen(s)==0||strlen(s)==1) return s;
    int i,count,left,right;
    int len=0,start=0;
    for(i=0;s[i]!='\0';i+=count){
    	count=1;
    	left=i-1;
    	right=i+1;
    	while(s[i]==s[right])
    	{
    		count++;
    		right++;
		}
    	while(left>=0&&s[left]==s[right]&&s[right]!='\0')
    	{
    		left--;
			right++;
		}
		if(right-left-1>len){
			len=right-left-1;
			start=left+1;
		}
	}
	s[start+len]='\0';
	return s+start;
}


bool divisorGame(int N){
    return N%2==0;
}


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














