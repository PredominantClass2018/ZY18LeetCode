/** 
 * 5. 最长回文子串
 */
 
 class Solution {
    public String longestPalindrome(String s) {
        if( s == null || s.length() == 0){
            return "";
        }

        int[] startAndEnd = new int[2];
        char[] str = s.toCharArray();

        for(int i = 0; i < s.length(); i++){
            i = findLongest(str, i, startAndEnd);
        }

        return s.substring(startAndEnd[0] , startAndEnd[1] + 1);

    }

    public int findLongest(char[] str, int i, int[] startAndEnd){
        int j = i;
        while(j < str.length - 1 && str[j + 1] == str[i]){
            j++;
        }

        int start = j;

        while(i > 0 && j < str.length - 1 && str[i - 1] == str[j + 1]){
            i--;
            j++;
        }

        if(j - i > startAndEnd[1] - startAndEnd[0]){
            startAndEnd[0] = i;
            startAndEnd[1] = j;
        }

        return start;

    }

}
