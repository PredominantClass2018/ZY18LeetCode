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
       for(int i=1;i<=arr.size();i++) //一组有多少个，窗口滑动
       {
           for(int j=0,l=i+j;l<=arr.size();j++,l++)  //j指示起点，l为第几个元素 
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
