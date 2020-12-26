//537
var complexNumberMultiply = function(a, b) {
    let alist = a.includes("+") ? a.split("+") : a.split("-")
    let blist = b.includes("+") ? b.split("+") : b.split("-")
    console.log(alist, blist)
    let r = alist[0] * blist[0] - parseInt(alist[1].slice(0, alist[1].length - 1)) * parseInt(blist[1].slice(0, blist[1].length - 1))
    let c = alist[0] * parseInt(blist[1].slice(0, blist[1].length - 1)) + parseInt(alist[1].slice(0, alist[1].length - 1)) * blist[0]
    console.log(r, c)

    return r + "+" + c + "i"
};
//153
var findMin = function(nums) {
    const len = nums.length;
    let ans = nums[0];

    for (let i = 1; i < len; i++) {
        (ans - nums[i] > 0) && (ans = nums[i]);
    }

    return ans;
};