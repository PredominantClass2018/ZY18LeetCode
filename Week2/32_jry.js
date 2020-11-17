var canPlaceFlowers = function(flowerbed, n) {
    // flag为记录总的种花位置数, num用于累计为0的项连续出现的次数
    var flag = 0, num = 1;
    // 末尾添加为0的项
    flowerbed.push('0');
    for(let i = 0; i < flowerbed.length+1; i++)
    {
        if (flowerbed[i] == 0){
            num++;
            if(num == 3)
            { 
                num = 1;
                flag++;
            }
        }
        else 
            num = 0;
    }
    return n <= flag;
};

/**
 每回合游戏都在数组的前两个元素（即 arr[0] 和 arr[1] ）之间进行。比较 arr[0] 与 arr[1] 的大小，较大的整数将会取得这一回合的胜利并保留在位置 0 ，较小的整数移至数组的末尾。当一个整数赢得 k 个连续回合时，游戏结束，该整数就是比赛的 赢家 。

返回赢得比赛的整数。

 */
var getWinner = function(arr, k) {
    let value = Math.max(arr[0],arr[1]);
    let num = 0;//连胜的回合
    let maxValue = value;
    if(k===1){
        return value;
    }
    for(let i=2;i<arr.length;i++){
        if(value>arr[i]){
            num++;
            if(num===k){
                return value;
            }
        }
        else{
            value = arr[i];
            num=1;
        }
        maxValue = Math.max(maxValue,arr[i]);

    }
    return maxValue;
};

var levelOrder = function(root) {
    if(!root){
        return [];
    }

    var queue = [];
    var result = [];
    var p = root;
    queue.push(root);
    queue[0].level = 1;
    while(queue.length !== 0){
        let i = queue.shift();
        if(i.left){
            queue.push(i.left);
            queue[queue.length - 1].level = i.level + 1;
        }
        if(i.right){
            queue.push(i.right);
            queue[queue.length - 1].level = i.level + 1;
        }
        if(!result[i.level - 1]){
            result[i.level - 1] = [];
        }
        result[i.level - 1].push(i.val);
        i.level = null;
        delete i.level;
    }
    return result;
};

