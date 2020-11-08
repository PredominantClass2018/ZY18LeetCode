//1588

class Solution {
 public:
     int sumOddLengthSubarrays(vector<int>& arr) {   
         int n=arr.size();
         int sum=0;
         for(int i=0;i<arr.size();++i){
             for(int j=i;j<n;j=j+2){
                 for(int k=i;k<j+1;++k){
                     sum+=arr.at(k);
                 }
             }
         }
         return sum;
     }
 };

//1550

 class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0,j=0;
        int num;
        for(i=0;i<arr.size();i=j+1){
            num=0;
            for(j=i;j<=i+2&&j<arr.size();++j){
                if(arr.at(j)%2==1) num++;
                else break;
            }
            if(num==3) {
                break;
            }
        }
        if(num==3) return true;
        else return false;
    }
};

 //120

 class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //���¶���
        //˼·���Ե�������⣬�ӵ����ڶ��п�ʼ�����нڵ㵽���һ�е���С·���͵��ڸýڵ�����ݼ�����������������������С��һ������ʹ�ö���ռ䣬ֱ�ӽ���С·���ʹ洢��ԭ�е������С�
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j= 0;j<triangle[i].size();++j){
                triangle[i][j]=min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};