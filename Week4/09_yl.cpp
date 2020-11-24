1401. 圆和矩形是否有重叠
class Solution {
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2) {
		float x0 = (x1 + x2) / 2.0;
		float y0 = (y1 + y2) / 2.0;//矩形的中心点(x0,y0)
		float len1 = abs(x0 - x_center); //中心点距离的横坐标
		float len2 = abs(y0 - y_center); //中心点距离的纵坐标
		float len3 = sqrt((x_center - x0)*(x_center - x0) + (y_center - y0)*(y_center - y0)); //中心点的距离
		float len4 = sqrt((x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1));
		if (len3>(len4 + radius))  return false;
		if (len1>(x2 - x0 + radius)) return false;
		if (len2>(y2 - y0 + radius)) return false;
		return true;
	}
};

704.二分查找
// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         for(int i=0;i<nums.size();++i){
//             if(nums.at(i)==target)  return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (target<nums.at(0) && target>nums.at(nums.size() - 1))  return -1;
		return zhong(0, nums.size() - 1, target, nums);
	}

	int zhong(int l, int r, int target, vector<int>& nums){
		int middle = (l + r) / 2;
		if (nums.at(middle) == target)  return middle;
		if (nums.at(l) == target) return l;
		if (nums.at(r) == target) return r;
		if (r - l == 1 && nums.at(l) != target && nums.at(r) != target)  return -1;
		if (r == l && nums.at(l) != target) return -1;

		if (target>nums.at(middle)) return zhong(middle, r, target, nums);
		if (target<nums.at(middle)) return zhong(l, middle, target, nums);
		return 0;
	}
};

189. 旋转数组
// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         k=k%nums.size();
//         for(int i=0;i<k;++i){
//             int m=nums.at(nums.size()-1);
//             for(int j=0;j<nums.size();++j){
//                 int temp=nums.at(j);
//                 nums.at(j)=m;
//                 m=temp;
//             }
//         }
//     }
// };


class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		int m = nums.size();
		vector<int> a(m);
		for (int i = 0; i<m; ++i){
			a.at((i + k) % m) = nums.at(i);
		}
		for (int i = 0; i<m; ++i){
			nums.at(i) = a.at(i);
		}
	}
};