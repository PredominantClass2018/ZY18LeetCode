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
