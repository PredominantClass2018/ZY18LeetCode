1
char * longestPalindrome(char * s){
    if(strlen(s)==0||strlen(s)==1) return s;
    int i,start,left,right,count,len;
    start = len =0;
    for(i=0;s[i]!='\0';i+=count){
        count = 1;
        left=i-1;
        right = i+1;
        while(s[right]!='\0'&&s[i]==s[right]){ //处理重复字符串
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
    s[start + len] = '\0';      // 原地修改返回
    return s + start;
}


2  
bool divisorGame(int N){
    if (N%2==0)
        return true;
    else 
        return false;
}


3
#define STU_NUM (200)

// 标记当前学生是否已经被发现
int g_fined[STU_NUM];
int findCircleNum(int** M, int MSize, int* MColSize){
    int cnt = 0;
    memset(g_fined,0,sizeof(g_fined));
    int que[STU_NUM] = {0};
    int front = 0;
    int rear = 0;
    for (int i=0;i<MSize;i++) {
        if(g_fined[i]!=0){continue;}
        que[rear] = i;
        g_fined[i] = 1;
        rear++;
        while(rear-front!=0){
            int now = que[front];
            front++;
            for(int j=0;j<MSize;j++){
                if(now!=j && g_fined[j]==0 && M[now][j]!=0){
                    // printf("now=%d,j=%d,rear=%d\n",now,j,rear);
                    que[rear] = j;
                    g_fined[j] = 1;
                    rear++;
                }
            }
        }
        cnt++;
        rear = 0;
        front = 0;
    }
    return cnt;
}



