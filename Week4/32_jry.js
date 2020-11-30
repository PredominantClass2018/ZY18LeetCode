    var arr = new Array();
    for(var i=1;i<=a;i++){
        arr.push(i);
    }
    return arr;
};


var exchange = function(nums) {
    var even = new Array();//偶数数组
    var odd = new Array();//奇数数组
    for(var i=1;i<nums.length;i++){
        if(nums[i]%2==0){
            even.push(nums[i]);
        }
        else{
            odd.push(nums[i]);
        }
    }
    var arr = new Array();
 return arr.concat(odd,even);
};

var reverseWords = function(s) {
    var arr = new Array();
    var arr2 = new Array();
    arr = s.split(" ");
    for(var i=0;i<arr.length;i++){
        arr2.unshift(arr[i]);
    }
    var arr3=arr2.filter((item)=>{
        return item !== ""
    })
    let str = arr3.join(" ");
    return str.trim();
};

 
