//朋友圈 
void dfs(int** M,int MSize,int* visted,int i){
	int j;
	int flag=0;
	if(visted[i]==0)  visted[i]=1;   
    for(j=0;j<MSize;++j){
    	if(M[i][j]!=0&&visted[j]==0){
		dfs(M,MSize,visted,j); 
		} 
	} 
} 
int findCircleNum(int** M, int MSize, int* MColSize){
	int i;
	int count=0;
	int visted[MSize];
	for(i=0;i<MSize;++i)
	  visted[i]=0;
	for(i=0;i<MSize;++i)
	if(visted[i]==0){
		dfs(M,MSize,visted,i);
		++count;
	}
	return count;
}

//最长回文子串 
class Solution {
public:
    string longestPalindrome(string s) {
    int n=s.size();
	vector<vector<int> >dp(n,vector<int>(n));
	string ss;
	int j,i,l;
	for(l=0;l<n;++l){
		for(i=0;i+l<n;++i)
		{
			j=i+l;
			if(l==0) {
			dp[i][j]=1;
			}
			else if(l==1){ 
			dp[i][j]=(s[i]==s[j]);
			} 
			else{
			dp[i][j]=(s[i]==s[j]&&dp[i+1][j-1]);
			}
		   if(dp[i][j]&&l+1>ss.size()){
		   	cout<<i<<l<<endl;
		   ss=s.substr(i,l+1);
		   }
	    }
		     
	}
	return ss;
	}
};

//除数博弈 
bool divisorGame(int N){
if(N%2==0) return true;
return false;
}
