//605 种花问题
//思路：如果要在一个位置种花，那么首先得确定该位置为0，而且该位置之前之后都没有种花
//		种植一朵花n--，直到n<=0时，返回true
var canPlaceFlowers = function(flowerbed, n) {
	for(var i=0;i<flowerbed.length;i++)
	{
		 if(!flowerbed[i]&&!flowerbed[i+1]&&!flowerbed[i+1])
		 {
			flowerbed[i]=1;
			n--;
			if(n<=0)
			return true;
		 }
	}
};
//1535 找出数组游戏的赢家
var getWinner = function(arr, k) {
	var prev=arr[0]>arr[1]?arr[0]:arr[1];
	if(k==1)
		return prev;
	var count=1;
	for(var i=2;i<arr.length;i++)
	{
		var cur=arr[i];
		if(prev>cur){
			count++;
		if(count>=k)
			return prev;
			}
		else 
		{
		prev=cur;
		count=1;
		}
	}
};
//32 从上到下打印二叉树（层次遍历）
/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function(root) {
if (root === null) {
    return [];
  }
  //创建队列并把起始节点入队(第一层)
  let queue = [],
    result = []
  queue.push(root)
  while (queue.length !== 0) {
    //从上一层节点拓展到下一层
    let level = [] //保存当前层过结果
    let size = queue.length //当前层的size
    for (let i = 0; i < size; i++) {
      node = queue.shift()
      level.push(node.val)
      if (node.left) {
        queue.push(node.left)
      }
      if (node.right) {
        queue.push(node.right)
      }
    }
    result.push(level)
  }
  return result;
};