704.
int search(int* nums, int numsSize, int target){
	int left = 0;
	int right = numsSize-1;
	while(left < right){
		int mid = left + right >> 1;
		if(nums[mid] >= target) right = mid;
		else left = mid + 1;
	}
	if(nums[left]==target) return left;
    else return -1; 	
}
1550.
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
         int cnt = 0;
         for(auto x:arr){
             if (x%2){
                 cnt++;
             }else{
                 cnt = 0;
             }
             if(cnt >= 3){
                 return true;
             }
         }
         return false;
    }
};

189.
void rotate(int* nums, int numsSize, int k){
	int start=0,cnt=0;
	int next,temp,cur,prev;

     k = k % numsSize;
	while(cnt<numsSize){
        cur=start;
        prev=nums[start];
    do{	
		next=(k+cur)%numsSize;
			
		temp=nums[next];
		nums[next]=prev;
		prev=temp;

		cur=next;
		cnt++;		
	  }while(next!=start);
	  start++;
	
	}
}
