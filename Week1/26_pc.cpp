//1、存在连续三个奇数的数组
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int i = 0; i < arr.size(); ++i){
            if (arr[i]%2 != 0)
                count++;
            else
                count = 0;
            if(count == 3)
                return true;
        }
        return false;
    }
}; 

//2、所有奇数长度子数组的和
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int t = 0;
        for(int i = 0; i < arr.size(); ++i){
            sum = 0;
            for(int j = i; j < arr.size(); ++j){
                sum += arr[j];
                if((j-i)%2 == 0)
                    t += sum;
            }
        }
        return t;
    }
};