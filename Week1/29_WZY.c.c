1.class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
       int flag=0;
       for(auto x:arr)
       {
           if(x%2!=0)
            flag++;
           else
            flag=0;
       }
       if(flag>=3)
        cout<<"true"<<endl;
       else
        cout<<"false"<<endl;
        return 0; 


    }
};

class Solution {
 public:
    int sumOddLengthSubarrays(vector<int> &arr) 
    { 
       int sum=0;
       for(int i=1;i<=arr.size();i++) //һ���ж��ٸ������ڻ���
       {
           for(int j=0,l=i+j;l<=arr.size();j++,l++)  //jָʾ��㣬lΪ�ڼ���Ԫ�� 
           {
               for(int k=j;k<l;k++)
               {
                   sum+=arr[k];
               }
           }
       }
      return sum;
    }
};
