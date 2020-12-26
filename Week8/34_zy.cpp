//复数乘法
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1,b1,a2,b2;
        sscanf(a.c_str(),"%d+%di",&a1,&b1);
        sscanf(b.c_str(),"%d+%di",&a2,&b2);

        int aa=a1*a2-b1*b2;
        int bb=a1*b2+a2*b1;

        return string(to_string(aa)+"+"+to_string(bb)+"i");
    }
};
//寻找旋转排序数据中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[n-1]>nums[0]) return nums[0];

        int left=0,right=n;
        while(left<right)
        {
            int mid=left+((right-left)>>1);
            if(nums[mid]>=nums[0])
                left=mid+1;
            else
                right=mid;               
        }
        return nums[left];
    }
};