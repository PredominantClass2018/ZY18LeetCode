题目：https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target/
class Solution {
public:
    vector<int> arr;
    int change(int x)
    {
        int sum = 0;
        for(auto item : arr)
        {
            if(item > x) item = x, sum += item;
            else sum += item;
        }

        return sum;
    }

    int findBestValue(vector<int>& A, int target) {
        arr = A;
        int r = *max_element(A.begin(), A.end());
        int l = 0;

        while(l < r)
        {
            int mid = (l + r) >> 1;
            if(change(mid) >= target) r = mid;
            else l = mid + 1;
        }

        int res = l;
        if(abs(change(res - 1) - target) <= abs(change(res) - target)) res = res - 1;
        
        return res; 
    }
};

https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)     {
        if(nums.empty()==1) return{-1,-1};
        else{
        
        int l=0,r=nums.size()-1;
        while(l<r)  //<=target中最大的
        {
            int mid=(l+r+1)>>1;
            if(nums[mid]<=target)   l=mid;
            else r=mid-1;
        }
        if(nums[l] != target) return{-1,-1};
        int L=l;
        l=0,r=nums.size()-1;
        while(l<r)      //<=target中最小的
        {
            int mid=(l+r)>>1;
            if(nums[mid]>=target ) r=mid;
            else l=mid+1;
        }
        return{r,L};
        }
        
    }
};