char * longestPalindrome(char * s){
    int left,right;
    int len;
    int l=0;
    int start;
    int i;

    if(strlen(s)==0||strlen(s)==1)
    {
        return s;
    }

    for(i=0;i<strlen(s);i++)
    {
        left=i-1;
        right=i+1;
        len=0;
        while(s[right]!='\0'&&s[right]==s[i])
        {
            right++;
            len++;
        }

        while(left>=0&&s[right]!='\0'&&s[left]==s[right])
        {
            len=len+2;
            left--;
            right++;
        }
        if(len>=l)
        {
            l=len;
            start=left+1;
        }
    }
    s[start+l+1]='\0';
    
    return s+start;
}



bool divisorGame(int N){
    if(N%2==0)
    return true;
    else
    return false;
}




void fuction(int **M,int MSize,int* MColSize, int i,int *visit)
{
    int j=0;
    visit[i]=1;
    for(j=0;j<MSize;i++)
    {
        if(M[i][j]==1&&visit[j]==0)
        {
            fuction(M,MSize,MColSize,j,visit);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    int i,j,n=0;
    int visit[MSize+1];

    for(i=0;i<MSize;i++)
    {
        visit[i]=0;
    }

    for(i=0;i<MSize;i++)
    {
        if(visit[i]==0)
        {
            fuction(M,MSize,MColSize,i,visit);  
            n++;
        }
    }

    return n;
}