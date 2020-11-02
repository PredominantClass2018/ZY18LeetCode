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
