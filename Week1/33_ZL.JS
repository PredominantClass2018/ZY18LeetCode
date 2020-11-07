//1588
var sumOddLengthSubarrays = function(arr) {
    let length = arr.length;
    let num = [];
    let sum = [];
    while (length > 0) {
        if (length % 2 == 1) {
            num.push(length)
        }
        length--;
    }
    for (let i = 0; i < num.length; i++) {
        for (let j = 0; j <= arr.length - num[i]; j++) {
            sum.push(arr.slice(j, j + num[i]).reduce((pre, cur) => pre + cur));
        }
    }
    return sum.reduce((pre, cur) => pre + cur);
};
//1550
var threeConsecutiveOdds = function(arr) {
    const n = arr.length;
    for (let i = 0; i <= n - 3; ++i) {
        if ((arr[i] % 2 !== 0) & (arr[i + 1] % 2 !== 0) & (arr[i + 2] % 2 !== 0)) {
            return true;
        }
    }
    return false;
};
//120
var minimumTotal = function(triangle) {
    var dp = triangle;
    for (var i = dp.length - 2; i >= 0; i--) {
        for (var j = 0; j < dp[i].length; j++) {
            dp[i][j] = Math.min(dp[i + 1][j], dp[i + 1][j + 1]) + dp[i][j];
        }
    }
    return dp[0][0];
};