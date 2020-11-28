1.class Solution {
public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
      int x;
      int y;
      if(x_center<x1) x=x1;
       else if(x_center>x2) x=x2;
       else x=x_center;
      if(y_center<y1) y=y1;
       else if(y_center>y2) y=y2;
       else y=y_center;
      int distant;
      distant=(x-x_center)*(x-x_center)+(y-y_center)*(y-y_center);
      int r=radius*radius;
      if(r>=distant)
       return true;
    else 
      return false;
    }
};

2.class Solution {
public:
    int search(vector<int>& nums, int target) {
      int end=nums.size()-1;
      int start=0;
      int mid;
      while(start<=end)
      {
          mid=start+(end-start)/2;
          if(nums[mid]==target)
           return mid;
          if(target<nums[mid])
           end=mid-1;
          else
           start=mid+1;
          
      }
      return -1;
         
    }
};


3.class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k%nums.size());
       reverse(nums.begin()+k%nums.size(),nums.end());
       
        
    }

