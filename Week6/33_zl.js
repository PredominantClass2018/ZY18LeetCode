//1300
var findBestValue = function(arr, target) {
    if (!arr) return 0;
    arr.sort((a, b) => a - b);
    let n = arr.length;
    let sum = 0;
    for (let i = 0; i < n; i++) {
        let x = (target - sum) / (n - i);
        if (x < arr[i]) return Math.round(x - 0.1);
        sum += arr[i];
    }
    return arr[n - 1];
};

//34 利用二分法不断来修改这个min值，缩小二分的范围来确定最后取值
var searchRange = function(nums, target) {

    function search(nums, target, first) {
        let len = nums.length,
            l = 0,
            h = len - 1;
        while (l < h) {
            let mid = l + ((h - l) >> 1)
            if (nums[mid] > target) {
                h = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                if (first) {
                    if (mid === 0 || nums[mid - 1] !== target)
                        return mid
                    h = mid - 1
                } else {
                    if (mid === len - 1 || nums[mid + 1] != target)
                        return mid
                    l = mid + 1
                }
            }
        }
        return -1
    }
    return [search(nums, target, true), search(nums, target)]
};