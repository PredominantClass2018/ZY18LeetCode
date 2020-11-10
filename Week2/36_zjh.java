/**
 * 605. 种花问题
 */
class Solution {
    public boolean canPlaceFlowers(int[] flowerbed, int n) {
      int i, j = 0;

        for(i = 0; i < flowerbed.length; i++){

            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.length - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                j++;
            }
            if(j >= n){
                return true;
            }


        }
        return false;
    }
}

/**
 * 1535. 找出数组游戏的赢家
 */
class Solution {
    public int getWinner(int[] arr, int k) {

        int win = 0;
        for(int i = 1; i < arr.length && win < k; i++){

            if(arr[i] < arr[0]){
                win++;
            }else{
                arr[0] = arr[i];
                win= 1;
            }
        }
        return arr[0];
    }
}

