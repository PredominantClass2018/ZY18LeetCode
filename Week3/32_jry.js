ar findRepeatNumber = function(nums) {

  for(let i=0;i<nums.length;i++){

​    for(let j=i+1;j<nums.length;j++){

​      if(nums[i]==nums[j]){

​        return nums[i];

​      }

​    }

  }

  return null;

};

var replaceSpace = function(s) {
    return s.split(' ').join('%20')
};

ar reversePrint = function(head) {
    var arr = [];
    while(head != null){
        arr.push(head.val);
        head=head.next;
    }
    return arr.reverse();
};
