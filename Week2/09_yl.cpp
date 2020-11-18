605.种花问题
class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int cnt = 0;
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.insert(flowerbed.end(), 0);
		for (int i = 1; i<flowerbed.size() - 1; ++i){
			if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
				cnt++;
				flowerbed[i] = 1;
			}

		}
		if (n <= cnt)  return true;
		return false;
	}
};

1535.找出数组的赢家
class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		int p = max(arr[0], arr[1]);
		int maxNum = p;
		if (k == 1) return p;
		int cnt = 1;
		for (int i = 2; i<arr.size(); ++i){
			int curr = arr[i];
			if (p>curr){
				cnt++;
				if (cnt == k) return p;
			}
			else{
				p = curr;
				cnt = 1;
			}
			maxNum = max(maxNum, p);
		}
		return maxNum;
	}
};

32.上到下按层打印二叉树
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		dfs(root, res, 0);
		return res;
	}
	void dfs(TreeNode* root, vector<vector<int>>& res, int level)
	{
		if (!root) return;
		if (level >= res.size()) res.emplace_back(vector<int>());
		res[level].emplace_back(root->val);
		dfs(root->left, res, level + 1);
		dfs(root->right, res, level + 1);
	}
};