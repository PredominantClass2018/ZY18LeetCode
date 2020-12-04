/**
 * 1550. 存在连续三个奇数的数组
 */
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

/**
 * 1588. 所有奇数长度子数组的和
 */
class Solution {
    public int sumOddLengthSubarrays(int[] arr) {

        int sum = 0;
        int lo, le, ro, re;
        for(int i = 0; i < arr.length; i++){
            lo = (i + 1) / 2;
            le = i / 2 + 1;
            ro = (arr.length - i ) / 2;
            re = (arr.length - 1 - i) / 2 + 1;
            sum += arr[i] * (lo * ro + le * re);
        }

        return sum;

    }
}

    /**
     * 120. 三角形最小路径和 c解决
     */

    int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
        for(int i = triangleSize - 2; i > -1; i--){
            for(int j = 0; j < triangleColSize[i]; j++){
                triangle[i][j] +=
                        triangle[i + 1][j] > triangle[i + 1][j + 1] ? triangle[i + 1][j + 1] : triangle[i + 1][j];
            }
        }
        return triangle[0][0];
    }
