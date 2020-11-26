class Solution {
public:
/*
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x0=(x1+x2)/2.0;
        double y0=(y1+y2)/2.0;

        vector<double> p={abs(x_center-x0),abs(y_center-y0)};
        vector<double> q={x2-x0,y2-y0};


        vector<double> u={max(p[0]-q[0],0.0),max(p[1]-q[1],0.0)};

        return sqrt(u[0] * u[0] + u[1] * u[1]) <= radius; 
    }
*/
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double dist=0;
        if(x_center<x1||x_center>x2){
            dist+=min((x1-x_center)*(x1-x_center),(x2-x_center)*(x2-x_center));
        }
        if(y_center<y1||y_center>y2){
            dist+=min((y1-y_center)*(y1-y_center),(y2-y_center)*(y2-y_center));
        }
        return dist<=radius*radius;
    }
};



class Solution {
public:
    int search(vector<int>& nums, int target) {
        int index;
        int left=0;
        int right=nums.size()-1;
        while(left<=right){
            index=left + (right-left)/2;
            if(nums[index]==target) return index;
            else if(nums[index]<target) left=index+1;
            else right=index-1; 
        }
        return -1;
    }
};



/*
class Solution {
public:
    //暴力求解
    void rotate(vector<int>& nums, int k) {
        for(int i=0;i<k;++i){
            int t=nums[nums.size()-1];
            for(int j=nums.size()-2;j>=0;--j){
                nums[j+1]=nums[j];
            }
            nums[0]=t;
        }
    }
};
*/
/*
class Solution {
public:
    //额外数组
    void rotate(vector<int>& nums, int k) {
        int num[nums.size()];
        for(int i=0;i<nums.size();++i){
            num[(i+k)%nums.size()]=nums[i];
        }
        for(int i=0;i<nums.size();++i){
            nums[i]=num[i];
        }
    }
};
*/
/*
class Solution {
public:
    //反转
    void reverse(vector<int>& nums, int start, int end) {
        while(start<end){
            int temp=nums[start];
            nums[start]=nums[end];
            nums[end]=temp;
            ++start;
            --end;
        }
    }
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};
*/

class Solution {
public:
    //循环
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int count=0;
        for(int i=0;count<nums.size();++i){
            int t=i;
            int temp=nums[i];
            do{
                int next=(t+k)%nums.size();
                int nextVal=nums[next];
                nums[next]=temp;
                temp=nextVal;
                t=next;
                count++;
            }while(i!=t);
        }
    }

};