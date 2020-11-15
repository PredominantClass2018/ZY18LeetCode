//605
var canPlaceFlowers = function(flowerbed, n) {
    var num = 0
    for (var i = 0, length = flowerbed.length; i < length; i++) {
        if (flowerbed[i] === 0 && flowerbed[i - 1] !== 1 && flowerbed[i + 1] !== 1) {
            num++
            i++
            //比较疑惑的是为啥还要加一，其实是因为当n有多个，当你插入一个1之后，后面的i+1是肯定不能加1了
        }
    }
    return n <= num
};
//1535
var getWinner = function(arr, k) {
        let time = 0
        let result = arr[0]
            //查看样例规律可以发现，当k的值大于arr数组中内容时，最终返回的都是arr数组中的最大值
        if (k >= arr.length) {
            return Math.max(...arr)
        }

        for (let i = 1; i < arr.length; i++) {
            if (result > arr[i]) {
                time++
            } else {
                time = 1
                result = arr[i]
            }
            if (k <= time) {
                return result
            }
        }
        return result
    }
    //OFFER 32
var levelOrder = function(root) {
    let ans = [],
        queue = [];

    if (root === null) return ans;

    queue.push(root);

    while (queue.length > 0) {
        let size = queue.length,
            temp = [];
        while (size > 0) {
            let offer = queue.shift();
            if (offer === null) continue;
            temp.push(offer.val);
            if (offer.left) queue.push(offer.left);
            if (offer.right) queue.push(offer.right);
            size--;
        }
        ans.push([...temp]);
        temp = [];
    }
    return ans;
};