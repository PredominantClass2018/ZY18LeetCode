//圆形和矩形是否有重叠 
class Solution {
public:
	bool max(double a,double b){
		if((a-b)>=0.0)return true;
		else return false;
		
	}
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x0=(x2+x1)/2.0;
        double y0=(y2+y1)/2.0;
        double p,q;
        double x22,y22;
        double x_center1; 
		double y_center1;
        x_center1=fabs(x_center-x0)*1.0;
        y_center1=fabs(y_center-y0)*1.0;
        x22=x2-x0;
        y22=y2-y0;
        p=x_center1-x22;
        q=y_center1-y22;
        cout<<p<<" "<<q<<endl;
        if(p<0&&q<0) return true;
        else if(p<0&&q>=0) {
        	if(max(radius,q))return true;
        	else return false;
		}
		else if(q<0&&p>=0) {
        	if(max(radius,p))return true;
        	else return false;
        }
        else if(p>=0 && q>=0) {
        	if(max(radius*radius,p*p+q*q)) return true;
        	else return false;
		}
	}
};

//旋转数组 
class Solution {
public:
	bool max(double a,double b){
		if((a-b)>=0.0)return true;
		else return false;
		
	}
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
        double x0=(x2+x1)/2.0;
        double y0=(y2+y1)/2.0;
        double p,q;
        double x22,y22;
        double x_center1; 
		double y_center1;
        x_center1=fabs(x_center-x0)*1.0;
        y_center1=fabs(y_center-y0)*1.0;
        x22=x2-x0;
        y22=y2-y0;
        p=x_center1-x22;
        q=y_center1-y22;
        cout<<p<<" "<<q<<endl;
        if(p<0&&q<0) return true;
        else if(p<0&&q>=0) {
        	if(max(radius,q))return true;
        	else return false;
		}
		else if(q<0&&p>=0) {
        	if(max(radius,p))return true;
        	else return false;
        }
        else if(p>=0 && q>=0) {
        	if(max(radius*radius,p*p+q*q)) return true;
        	else return false;
		}
	}
};

//二分查找 
class Solution {
  public:
  int search(vector<int>& nums, int target) {
    int pivot, left = 0, right = nums.size() - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (nums[pivot] == target) return pivot;
      if (target < nums[pivot]) right = pivot - 1;
      else left = pivot + 1;
    }
    return -1;
  }
};
