//1025
var divisorGame = function(N) {
    if (N % 2 == 0) {
        return true;
    } else {
        return false;
    }
};
//547
var findCircleNum = function(M) {
    let n = M.length;
    if (n == 0) {
        return 0;
    }
    let count = 0;
    let dfs = (i) => {
        for (let j = 0; j < n; j++) {
            if (M[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(j);
            }
        }
    }
    let visited = {};
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }
    return count;
};
//5
var longestPalindrome = function(s) {
    if (s.length < 2) {
        return s;
    }
    let start = 0;
    let maxLength = 1;

    function Center(left, right) {
        while (left >= 0 && right < s.length && s[left] === s[right]) {
            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }
            left--;
            right++;
        }
    }
    for (let i = 0; i < s.length; i++) {
        Center(i - 1, i + 1);
        Center(i, i + 1);
    }
    return s.substring(start, start + maxLength);
};