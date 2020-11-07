//120
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int f[triangleSize][triangleSize];
    memset(f, 0, sizeof(f));
    f[0][0] = triangle[0][0];
    for (int i = 1; i < triangleSize; ++i) {
        f[i][0] = f[i - 1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            f[i][j] = fmin(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
        }
        f[i][i] = f[i - 1][i - 1] + triangle[i][i];
    }
    int ret = f[triangleSize - 1][0];
    for (int i = 1; i < triangleSize; i++)
        ret = fmin(ret, f[triangleSize - 1][i]);
    return ret;

}

//1588
int sumOddLengthSubarrays(int* arr, int arrSize){
    /*int i,sum;
    for(i=0;i<arrSize;++i)
    {
        int leftodd=(i+1)/2,lefteven=i/2+1;
        int rightodd=(arrSize-i)/2,righteven=(arrSize-1-i)/2+1;
        sum+=arr[i]*(leftodd*rightodd+lefteven*righteven);
    }*/
    int i,j,sum=0,len;
    for(len=1;len<=arrSize;len+=2)
    {
        for(i=0;i+len<=arrSize;i++)
        {
            for(j=i;j<i+len;j++)
            sum+=arr[j];
        }
    }
    return sum;
}

//1550
bool threeConsecutiveOdds(int* arr, int arrSize){
    /*
    int i;
    for(i=0;i<arrSize-2;i++)
    {
        if((arr[i]%2==1)&&(arr[i+1]%2==1)&&(arr[i+2]%2==1))
        return true;
    }
    return false;
    */
    int i= 0 ;
        while(true) 
        {
            while(arr[i] % 2 == 0)
            {
                i++;
                if(i>= arrSize - 2) 
                {
                    break;
                }
            }
            if(i >= arrSize- 2) 
            {
                break;
            }
            if(arr[i + 1] % 2 == 0 || arr[i + 2] % 2 == 0) 
            {
                i++;
                continue;
            }
            return true;
        }
        return false;
}
