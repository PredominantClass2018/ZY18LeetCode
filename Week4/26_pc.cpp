//1、圆和矩形是否有重叠
  bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        double x0 = (x1 + x2) / 2.0;
        double y0 = (y1 + y2) / 2.0;

        vector<double> p = { abs(x_center - x0) , abs(y_center - y0) };
        vector<double> q = { x2 - x0, y2 - y0 };

        vector<double> u = { max(p[0] - q[0], 0.0), max(p[1] - q[1], 0.0) };

        return sqrt(u[0] * u[0] + u[1] * u[1]) <= radius;
    }


//2、二分查找
class Solution {
public:
    int search(vector<int>& nums, int target){
        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(target == nums[mid]){
                return mid;
            }else if(target > nums[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return -1;
    }
};

//3、旋转数组
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int array[n];
        for(int i = 0; i < n; ++i){
            array[(i+k)%n] = nums[i];
        }
        for(int i = 0; i < n; ++i){
            nums[i] = array[i];
        }
    }
};
