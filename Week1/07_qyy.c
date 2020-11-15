int sumOddLengthSubarrays(int* arr, int arrSize){
    int i,j,k;
    int sum=0;
    for(i=1;i<=arrSize;i+=2)//子数组长度1,3,5
    {
        for(j=0;j<arrSize-i+1;j++)//
        {
            for(k=0;k<i;k++)
            {
                sum+=arr[j+k];
            }
        }
    }
    return sum;
}

bool threeConsecutiveOdds(int* arr, int arrSize){
    int i;
    for(i=1;i<arrSize-1;i++)
    {
        if(arr[i-1]%2==1 && arr[i]%2==1 && arr[i+1]%2==1)
        {    
            return true;
        }
    }
    return false;
}
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
~
07_qyy.c [unix] (07:59 01/01/1970)                                      0,1 全部
-- 插入 --

