/////////////////////////////////////////////////// 计算回文数 
int  Palindrome(char* p, int pos, int *lenPa)
{
    int len = strlen(p) - pos;
    int i,pos2;
    char ch;

    ch = p[pos];
    /* 计算传入的位置的字符后面是不是有相同的字符。比如传入的位置字符是a,位置后面有相同的字符aaaab，那么需要得到最后一个a的位,即pos2*/
    for(i = 1; i < len; i++)
    {
        if(p[pos + i] != ch)
        {
            break;
        }
    }
    pos2 = pos + i - 1;


    /* cgdgaaaaagb, 计算回文数。pos，第一个a的位置； pos2,第二个a的位置。pos减，pos2加，比较是否相等，即是否是回文数，得到最长的回文数 */
    for(i = 1;  (i < len && pos - i >= 0); i++)
    {
        if(p[pos - i] != p[pos2 + i])
        {
            break;
        }
    }
    *lenPa = ((i - 1) * 2 + (pos2 - pos) + 1); /* 回文数的最终长度 */

    return pos-(i-1); /* 回文数的起始位置 */

}

char * longestPalindrome(char * s){
    int max = 0, count, i, pos = 0;
    int len = strlen(s); /* 计算给定的字符串的长度 */
    char *buf = (char*)malloc(len+1); /* 申请堆空间，写死的话至少1001。*/

    for(i = 0; i < len; i++)
    {
        /* 传入字符串s，给一个位置i, 得到回文数的长度count，并且返回回文数的起始位置 */
        pos = Palindrome(s, i, &count); 
        if(count > max)
        {
            max = count;
            memcpy(buf, &s[pos], max);/* 保存回文数 */
        }
    }
    printf("%d\n", max);
    buf[max] = '\0';
    return buf;
}


/////////////////////////////////除数博弈
bool divisorGame(int N) {
    return N % 2 == 0;
}


/////////////////////////////////朋友圈
struct node {
    int father;
    int weight;
};

int count = 0;
int find(struct node* f, int x)
{
    while (f[x].father != x) {
        x = f[x].father;
    }
    return x;
}

void merge(int x, int y, struct node* f)
{
    int rootx = find(f, x); /* 找根节点 */
    int rooty = find(f, y); /* 找根节点 */

    if (rootx == rooty) {
        return;
    }

    if(f[x].weight > f[y].weight) { /* 按权值合并 */
        f[rooty].father = rootx;
        f[rootx].weight += f[rooty].weight;
    } else {
        f[rootx].father = rooty;
        f[rooty].weight += f[rootx].weight;
    }
    count--;
}

int findCircleNum(int** M, int MSize, int* MColSize){
    struct node *f = (struct node*)calloc(MSize, sizeof(struct node));
    
    count = MSize; /* 初始化朋友数量为学生数量，即每个学生一个朋友圈 */
    int i;
    for (i = 0; i < MSize; i++) {
        f[i].father = i; /* 初始化各个节点的fater为自己 */
        f[i].weight = 1; /* 初始化权值为1 */
    }

    for (i = 0; i < MSize; i++) {
        for (int j = 0; j < *MColSize; j++) {
            if(i != j && M[i][j] == 1) {
                merge(i, j , f);
            }
        }
    }
    free(f);
    return count;
}

