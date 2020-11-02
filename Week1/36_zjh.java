class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        int t = 0;
        for(int i = 0; i < arr.length; i++){
            if(arr[i] % 2 == 1){
                t++;
            }else{
                t = 0;
            }
            if(t >= 3){
                return true;
            }
        }
        return false;
    }
}
