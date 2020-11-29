//704 二分法查找，使用两个指针同时进行查找，谁先找到先返回谁
var search = function(nums, target) {
    let i = 0,
        j = nums.length;
    while (i <= j) {
        if (nums[i] === target) return i;
        if (nums[j] === target) return j;
        i++;
        j--;
    }
    return -1
};
//1401 在已知的信息条件下，选取最近的一个坐标点的距离和圆半径长度进行比较，如果小于则一定有交集
//对于x、y坐标存在三种不同的情况，圆心坐标位于最左边、中间、最右边然后去选择进行计算
var checkOverlap = function(radius, x_center, y_center, x1, y1, x2, y2) {
    //对x进行坐标最小值的选择
    var dx = x1 > x_center ? x1 - x_center : x2 < x_center ? x_center - x2 : 0
        //对y进坐标最小值的选择
    var dy = y1 > y_center ? y1 - y_center : y2 < y_center ? y_center - y2 : 0
    return dx * dx + dy * dy <= radius * radius
};
//189 刚开始想的是循环进行扫描一遍，将源数组的对应下标值+k之后存到另一个数组中去，但是题目要求是复杂度为O(1),EMMM……可以把数组中的所有数右移k位，把超出的部分移到最前面,最后将超出的内容截断
var rotate = function(nums, k) {
    let l = nums.length;
    for (var i = 0; i < nums.length; i++) nums[i + k] = nums[i]
    for (var i = k; i--;) nums[i] = nums[nums.length - k + i]
    nums.length = l;
};