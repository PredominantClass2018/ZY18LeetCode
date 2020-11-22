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

/**
 * 1025. 除数博弈
 */
class Solution {
    public boolean divisorGame(int N) {
        return (N&1) == 0;
    }
}

/**
 * 547. 朋友圈
 */
class Solution {
    public int findCircleNum(int[][] M) {
        int N = M.length;
        UnionSearchSet unionSearchSet = new UnionSearchSet(N);
        for (int row = 0; row < N; ++row) {
            for (int column = row + 1; column < N; ++column) { // 不需要从0开始判断
                if (M[row][column] == 1) unionSearchSet.union(column, row);
            }
        }
        return unionSearchSet.countSetNumber();
    }
}

class UnionSearchSet{
    private int[] unionsearch;

    UnionSearchSet(int n){
        unionsearch = new int[n];
        for(int i = 0; i < n; i++){
            unionsearch[i] = i;
        }
    }

    void union(int person1, int person2){
        int x = find(person1);
        int y = find(person2);
        if(x != y){
            unionsearch[x] = y;
        }
    }

    int find(int person){
        if(person == unionsearch[person])
            return person;
        return unionsearch[person] = find(unionsearch[person]);
    }

    public int countSetNumber(){
        int count = 0;
        for(int i = 0; i < unionsearch.length; i++){
            if(unionsearch[i] == i)
                count++;
        }
        return count;
    }
}




