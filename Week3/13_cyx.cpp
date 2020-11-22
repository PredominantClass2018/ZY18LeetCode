5. ������Ӵ�
char * longestPalindrome(char * s){
    int N = strlen(s), start = 0, len = 0;  // N �ַ������ȣ� start �Ӵ���ʼλ�ã� len �Ӵ�����
    for (int i = 0; i < N; i++) {   // �������ȵĻ����Ӵ�
        int left = i - 1, right = i + 1;
        while (left >= 0 && right < N && s[left] == s[right]){
            left--; right++;            // �� i Ϊ���ģ����������죬ֱ�������������
        }                               // left+1 ~ right-1 ��Ϊ��iΪ���ĵ��������Ӵ�
        if (right - left - 1 > len) {   // ���������򱣴���Ӵ���Ϣ
            start = left + 1;
            len = right - left - 1;
        }
    }
    for (int i = 0; i < N; i++) {   // ż�����ȵĻ����Ӵ�
        int left = i, right = i + 1;    // �� i+0.5 Ϊ���ģ�����������
        while (left >=0 && right < N && s[left] == s[right]) {
            left--, right++;
        }
        if (right - left - 1 > len) {
            start = left + 1;
            len = right - left - 1;
        }
    }
    s[start + len] = '\0';      // ԭ���޸ķ���
    return s + start;
}

547. ����Ȧ
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

1025. ��������
bool divisorGame(int N){
    if(N%2==0)
    return true;
    else  
    return false;
}




