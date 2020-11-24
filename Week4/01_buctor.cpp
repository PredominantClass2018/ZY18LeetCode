//704
//https://leetcode-cn.com/problems/binary-search/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(l >= 0 && l < nums.size() && nums[l]==target) return l;
        else return -1; 
    }
};

//https://leetcode-cn.com/problems/rotate-array/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        int i = 0, j = nums.size() - 1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        i = 0,j=k-1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;            
        }
        i = k, j = nums.size() - 1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;            
        }
    }
};

//https://leetcode-cn.com/problems/circle-and-rectangle-overlapping/
class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        if(x1 > x_center + radius || x2 < x_center - radius) return false;
        if(y1 > y_center +radius || y2 < y_center - radius) return false;
        if(x1 > x_center && y1 > y_center && calculate(x1,y1,x_center,y_center,radius)) return false;
        if(x2 < x_center && y2 < y_center && calculate(x2,y2,x_center,y_center,radius)) return false;
        if(x1 > x_center && y2 < y_center && calculate(x1,y2,x_center,y_center,radius)) return false;
        if(x2 < x_center && y1 > y_center && calculate(x2,y1,x_center,y_center,radius)) return false;
        return true;
    }
    bool calculate(int x,int y,int x_center,int y_center,int radius)
    {
        double a = abs(x - x_center);
        double b = abs(y - y_center);
        double r = sqrt(a*a + b*b);
        if(r>radius) return true;
        else return false;
    }
};