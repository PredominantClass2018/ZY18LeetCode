//704
//暴力解法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            if(nums.at(i)==target) return i;
        }
        return -1;
    }
};
//二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        int result=0;
        while (left <= right)
        {
            int mid = (right + left) / 2;
            if (nums.at(mid) == target) {
                return mid;
            }
            else if(nums.at(mid)>target) {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            } 
        }
        return  -1 ;
    }
};
//189
//暴力解法
class Solution {
public:
/*
先判断nums长度是否小于2，小于的话无论循环几次都是本身
不小于的话要判断长度与k的大小
大于的话就将nums.size()-k后面的元素直接复制给arr，再把nums前面的数组赋值给arr
否则就将m=k%(nums.size()),然后将对应位赋值

*/
    void rotate(vector<int>& nums, int k) {
        vector<int>arr;
        if(nums.size()<2) return;
        if(nums.size()>=k){
            for(int i=nums.size()-k;i<nums.size();i++){
            arr.push_back(nums.at(i));
            }
            for(int i=0;i<nums.size()-k;i++){
                arr.push_back(nums.at(i));
            }
            nums.clear();
            for(int i=0;i<arr.size();i++)
            {
                nums.push_back(arr.at(i));
            }
        }else{
            int m=k%nums.size();
            if(m==0) return;
            else{
                for(int i=nums.size()-m;i<nums.size();i++){
                arr.push_back(nums.at(i));
                }
                for(int i=0;i<nums.size()-m;i++){
                    arr.push_back(nums.at(i));
                }
                nums.clear();
                for(int i=0;i<arr.size();i++)
                {
                    nums.push_back(arr.at(i));
                }
            }
        }
    }
};

//1401
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        int x, y;

        if(x_center > x2) x = x2;
        else if(x_center < x1) x = x1;
        else x = x_center;

        if(y_center > y2) y = y2;
        else if(y_center < y1) y = y1;
        else y = y_center;

        int dist = sqrt((x - x_center) * (x - x_center) + (y - y_center) * (y - y_center));
        if(dist <= radius)
            return true;
        return false;
    }
};