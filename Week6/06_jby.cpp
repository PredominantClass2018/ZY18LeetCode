//查找元素 
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     	int left,right,mid;
     	vector<int>data;
		if(nums.size()==0){   //没有元素返回错误 
			vector<int> data;
			data.push_back(-1);
			data.push_back(-1);
			return data;
		}
		left=0;
		right=nums.size()-1;
		
		while(left<right){   //寻找左边界 
			mid=(left+right)/2;
			if(nums[mid]<target)
		  		left=mid+1;
			else
		 		right=mid; 	
		}
		if(nums[left]==target)
			data.push_back(left);
		else
        {
        	data.push_back(-1);
        	data.push_back(-1);
        	return data;
		}
		
		left=0;
		right=nums.size()-1;
		while(left<right){     //寻找右边界 
			mid=(left+right+1)/2;
			if(nums[mid]<=target)
		  		left=mid;
			else
		 		right=mid-1; 	
		}
		data.push_back(right);
		
		return data;
    }
};




//转变数组后接近目标值 
class Solution {
public:
    float findBestValue(vector<int>& arr, int target) {
    	int begin,end,data;
    	begin=0;
    	end=arr.size()-1;
    	data=0;
    	for(int i=0;i<arr.size();i++){
    		data+=arr[i];
		}
		if(data<=target) { 
		sort(arr.begin(),arr.end());
		
		 return arr[arr.size()-1];
		}
    while(end>begin){
	  data=find_correct(arr,&target,&begin,&end);
	  if(data<=arr[begin]) break;
	}
    return data;
}
int find_correct(vector<int>&arr,int* target,int* begin,int *end){//begin,end均代指下标 
    int avl;
    int count=0;
	int rev; 
	int max=0;
	float data;
    avl=(*target)/((*end)-(*begin)+1);
    rev=(*target);
    for(int i=(*begin);i<=(*end);++i){
	    if(arr[i]<=avl){
			rev-=arr[i];
			++count; 
		} 
		if(arr[i]>max){
			max=arr[i];
		}
		
	}
    	data = floor((rev*0.1/(((*end)-(*begin)+1)-count)+0.04)*10);
		if(data>max)  {
		data=max;
		(*end)=0;
		} 
		(*begin)=(*begin)+count;
		(*target)=rev;
	     return   data;
}
};





