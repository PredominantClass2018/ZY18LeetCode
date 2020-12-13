//转变数组后最接近目标值的数组和
class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int sum=0;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            double tmp=(double)(target-sum)/(n-i);
            if(arr[i]>tmp)
                return int(tmp+0.4);//判断是取当前值还是加一
            sum+=arr[i];
        }
    return arr[n-1];
    }
};
//在排序数组中查找元素的第一个和最后一个位置
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] res=new int[]{-1,-1};
        res[0]=binarySearch(nums,target,true);//找左边界
        res[1]=binarySearch(nums,target,false);//找右边界
        return res;
    }
    public int binarySearch(int[] nums,int target,boolean leftORright)
    {
        int res=-1;
        int left=0,right=nums.length-1,mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(target<nums[mid])
                right=mid-1;
            else if(target>nums[mid])
                left=mid+1;
            else{
                res=mid;
                if(leftORright)    right=mid-1;
                else               left=mid+1;
            }
        }
        return res;
    }
}