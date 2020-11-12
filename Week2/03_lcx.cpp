//LeetCode 605
//https://leetcode-cn.com/problems/can-place-flowers/

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		flowerbed.insert(flowerbed.begin(), 0);
		flowerbed.insert(flowerbed.end(), 0);
		for (int i = 1; i < flowerbed.size() - 1; flowerbed[i] ? i += 2 : ++i) {
			if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
				flowerbed[i] = 1;
				--n;
			}
			if (n <= 0)
				return true;
		}
		return n <= 0;
	}
};

//LeetCode 1535
//https://leetcode-cn.com/problems/find-the-winner-of-an-array-game/

class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		std::ios::sync_with_stdio(false);
		int ans = arr[0];
		int first = 0;
		int last = first + k > arr.size() - 1 ? arr.size() - 1 : first + k;
		while (true) {
			for (int i = first; i <= last; ++i)
				if (arr[first] < arr[i])
					first = i;
			if (ans == arr[first])
				break;
			ans = arr[first];
			last = first + k - 1 > arr.size() - 1 ? arr.size() - 1 : first + k - 1;
		}
		return ans;
	}
};

//LeetCode ½£Ö¸Offer 32 - II
https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/

class Solution {
private:
	vector<vector<int>> ans;
	void dfs(const TreeNode* root, int n) {
		if (!root)
			return;
		if ((int)ans.size() - 1 < n)
			ans.push_back({ root->val });
		else
			ans[n].push_back(root->val);
		dfs(root->left, n + 1);
		dfs(root->right, n + 1);
		return;
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
};
