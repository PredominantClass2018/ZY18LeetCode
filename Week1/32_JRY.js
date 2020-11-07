/*
 连续三个奇数
 */
var threeConsecutiveOdds = function(arr) {
    var flag=0;
    for(var i=0;i<arr.length;i++){
        if(arr[i]%2==0){
            flag=0;
        }
        else{
            flag++;
        }
         if(flag===3){
            return true;
        }
    }
    return false;
};


/*
 奇数组
 */
var sumOddLengthSubarrays = function(arr) {
    let sum = 0
    for(let i = 1;i <= arr.length;i += 2){      //数组的长度为1~arr.length 每次+2为奇数组
        for(let j = 0;j <= arr.length-i;j++){        //定义有效子数组长度
            sum += arr.slice(j,j + i).reduce((acc,cur) => acc + cur,0)
        }
    }
    return sum;
}

/*
 最短路径
 */
var minimumTotal = function(triangle) {
    var a = triangle;
    for(let i=a.length-2;i>=0;i--){     //  自下而上
        for(var j=0;j<a[i].length;j++){
            a[i][j]=Math.min(a[i+1][j],a[i+1][j+1])+a[i][j];
        }
    }
    return a[0][0];
};
