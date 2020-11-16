bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int i;
	int flag=0;
	if(n==0) return true;
	if(flowerbedSize==1)
	{
		if(flowerbed[0]==0&&n==1)  return true;
		else return false;
	}
	if(flowerbed[0]==0&&flowerbed[1]==0) 
	{
		flowerbed[0]=1;
	      ++flag;
	}
	
	for(i=1;i<=flowerbedSize-2;++i)
	if(flowerbed[i-1]==0&&flowerbed[i]==0&&flowerbed[i+1]==0)
	{
	  flag++;
	  flowerbed[i]=1;
	   
	} 
	if(flowerbed[flowerbedSize-1]==0&&flowerbed[flowerbedSize-2]==0) flag++;

	if(flag>=n) return true;
	return false;
		
}


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int max=0;
        int count;
        int i,j;
        if(k>=arr.size()-1)
        {
        	auto d=max_element(arr.begin(),arr.end());
        	return *d;
		}
        for(i=0;i<arr.size();i++)
        {
        	if(arr[i]>max)
        	{
        		max=arr[i];
        		count=1;
        		if(i==0) count--;
        		j=i+1;
        		if(j==arr.size()) j=j%arr.size();
        		while(arr[i]>=arr[j])
        		 {
				 ++j;
				 ++count;
			     if(count>=k) return arr[i];
			     if(j==arr.size()) j=j%arr.size();
				 }
				  if(count>=k) return arr[i];
			}
		}
		return i;
    }
};

vector<vector<int> >ret;
        if(!root)  return ret;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
        	int levelszie=q.size();
        	ret.push_back(vector<int>());
            for(int i=0;i<levelszie;i++)
            {
            	TreeNode* node=q.front();q.pop();
                ret.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
			}
		}
        
            return ret;
