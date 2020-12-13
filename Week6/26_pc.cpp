//1、
class Solution {
public:
    int check(const vector<int>&arr,int x){
        int ret = 0;
        for(const int &num : arr){
            ret += (num>=x?x:num);
        }
        return ret;
    }
    int findBestValue(vector<int>& arr, int target) {
        int len = arr.size();
        sort(arr.begin(),arr.end());
        vector<int>findsum(len+1);
        for(int i = 1; i <= len; ++i){
            findsum[i] = findsum[i-1]+arr[i-1];
        }

        int ans = 0, left = 0, right = *(max_element(arr.begin(),arr.end()));//right是容器中最大值
        while(left <= right){//二分是以值为标准而非下标
            int mid = left+((right-left)>>1);
            auto iter = lower_bound(arr.begin(),arr.end(),mid);//二分查找容器中值为
            int sum = findsum[iter-arr.begin()]+(arr.end()-iter)*mid;
            if(sum <= target){//mid值小了
                left = mid+1;
                ans = mid;
            }else{//mid值大了
                right = mid-1;
            }
        }
        int small = check(arr,ans);
        int big = check(arr,ans+1);
        return abs(small-target) <= abs(big-target)?ans:ans+1;
    }
};

//2、排序数组中查找第一个和最后一个
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        vector<int>v;
        if(!n) return {-1,-1};//容器为空
        for(int i = 0; i < n; ++i){
            if(nums[i]==target){
                v.push_back(i);
                count = i;
                while(count < n && nums[count]==target)
                    count++;
                v.push_back(count-1);
                return v;
            }
        }
        return {-1,-1};
    }
};
