1.
int minNumberOfFrogs(char * croakOfFrogs){
    int c = 0, r = 0, o = 0, a = 0, k = 0;
    int len = strlen(croakOfFrogs);
    int i = 0, res = 0;
    char ch;
    for (i = 0; i < len; i++){
        ch = croakOfFrogs[i];
        if (ch == 'c')   c++;
        else if (ch == 'r')   r++;
        else if (ch == 'o')   o++;
        else if (ch == 'a')   a++;
        else if (ch == 'k')   k++;
        if((c-k)>res)   res=c-k;
        if (c >= r && r >= o && o >= a && a >= k)   continue;
        return -1;
    }
    if (c == r && r == o && o == a && a == k)   return res;
    return -1;
}





2.
int longestWPI(int* hours, int hoursSize){
    int f[hoursSize+2],s[hoursSize+2],dec_list[hoursSize+2];
    f[0] = 0;
    for (int i=0; i<hoursSize; i++)
        f[i+1]=(hours[i]>8?1:-1);
    int tmp=0,dsize=0;
    for (int i=0; i<hoursSize+1; i++){
        tmp += f[i];
        s[i] = tmp;
        if (dsize==0 || s[dec_list[dsize-1]]>tmp){
            dec_list[dsize] = i;
            dsize += 1;
        }
    }
    int n=hoursSize,res=0;
    dsize -= 1;
    while (n>=0){
        while (dsize>=0 && s[dec_list[dsize]]<s[n]){
            if(res<=n-dec_list[dsize])   res=n-dec_list[dsize];
            dsize -= 1;
        }
        n-=1;
    }
    return res;
}

