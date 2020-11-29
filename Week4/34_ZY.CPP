//圆和矩形是否有重叠
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        //若圆形在矩形四边，则返回false
        if(x_center+radius<x1||x_center-radius>x2||y_center+radius<y1||y_center-radius>y2)
            return false;
        
        //判断圆心到矩形中心距离与圆的半径和矩形对角线长度一半的大小关系
        double distance=sqrt(pow(x_center-(x1+x2)/2,2)+pow(y_center-(y1+y2)/2,2));
        double length=sqrt(pow(x2-x1,2)+pow(y2-y1,2))/2+radius;

        return distance<=length;
    }
};
//二分查找
int search(int* nums, int numsSize, int target){
    int low=0,high=numsSize-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]<target)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}
//旋转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        reverse(nums.begin(), nums.end());  // 全数组翻转
        reverse(nums.begin(), nums.begin()+k);  // 前k项翻转
        reverse(nums.begin()+k, nums.end());  // 后n-k项翻转
    }
};
