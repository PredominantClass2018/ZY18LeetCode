/*
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> presum(arr.size()+1);
        for(int i=1;i<=arr.size();++i){
            presum[i]=presum[i-1]+arr[i-1];
        }
        int diff=target;
        int ans=0;
        int n=arr.size();
        int max = *max_element(arr.begin(), arr.end());
        for(int i=1;i<=max;++i){
            auto iter = lower_bound(arr.begin(), arr.end(), i);
            int sum=presum[iter-arr.begin()]+i*(arr.end()-iter);
            if(abs(sum-target)<diff){
                ans=i;
                diff=abs(sum-target);
            }
        }
        return ans;
    }
};
*/
class Solution {
public:
    int check(vector<int> &arr,int x){
        int sum=0;
        for(const int&num:arr){
            sum+=(num>x?x:num);
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<int> presum(arr.size()+1);
        for(int i=1;i<=arr.size();++i){
            presum[i]=presum[i-1]+arr[i-1];
        }
        int l=0,r=*max_element(arr.begin(),arr.end());
        int mid=0;
        int ans=-1;
        ans=0;
        while(l<=r){
            mid=(l+r)/2;
            auto iter=lower_bound(arr.begin(),arr.end(),mid);
            int sum=presum[iter-arr.begin()]+(arr.end()-iter)*mid;
            if(sum<=target){
                ans=mid;
                l=mid+1;
            }
            else {
                r=mid-1;
            }
        }
        return abs(check(arr,ans)-target)<=abs(check(arr,ans+1)-target)?ans:ans+1;
    }
};





class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target)) {
                right = mid - 1;
                ans = mid;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int left=binarySearch(nums,target,true);
        int right=binarySearch(nums,target,false)-1;
        if(left<=right&&right<nums.size()&&nums[left]==target&&nums[right]==target){
            return {left,right};
        } 
        return {-1,-1};
    }
};
