//1588 ������������������ĺ�
int sumOddLengthSubarrays(int* arr, int arrSize){
    int count=0;//���ۼ����ĺ�
    int temp;//ѭ��һ�εļ���
    for(int i=0;i<arrSize;i++) {
        temp=0;
        for(int j=i;j<arrSize;j++) {
            if((j-i+1)%2) {
                temp+=arr[j];
                count+=temp;
            }
            else {
                temp+=arr[j];
            }
        }
    }
    return count;
}
//1550 ����������������������
bool threeConsecutiveOdds(int* arr, int arrSize){
    for(int i = 2 ; i < arrSize; i++){
        if((arr[i] % 2) && (arr[i - 1] % 2)&& (arr[i - 2 ]%2)){
            return true;
        }
    }
    return false;
}
//120 ��������С·����
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) 
{
    int n=triangleRowSize;
    int* tmp=triangle[n-1];
    for(int i=n-2;i>=0;i--)
    {
        int m=triangleColSizes[i];
        for(int j=0;j<m;j++)
        {
            int min=tmp[j]<tmp[j+1]?tmp[j]:tmp[j+1];
            tmp[j]=triangle[i][j]+min;
        }
    }
    return tmp[0];   
}