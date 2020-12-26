//1124
var longestWPI = function(hours) {
    let preSum = new Array(hours.length + 1).fill(0)
    for (let i = 1; i <= hours.length; i++) {
        if (hours[i - 1] > 8) preSum[i] = preSum[i - 1] + 1
        else preSum[i] = preSum[i - 1] - 1
    }
    let max = 0
    for (let i = 0; i < preSum.length - 1; i++) {
        for (let j = i + 1; j < preSum.length; j++) {
            if (preSum[j] - preSum[i] > 0) {
                max = Math.max(max, j - i)
            }
        }
    }
    return max
};
//1419
var minNumberOfFrogs = function(croakOfFrogs) {
    if (croakOfFrogs.length === 0) { return 0; }
    if (croakOfFrogs.length % 5 !== 0) { return -1; }

    let maxCount = croakOfFrogs.length / 5;
    let c = maxCount;
    let r = maxCount;
    let o = maxCount;
    let a = maxCount;
    let k = maxCount;

    let finishedCount = 0;

    for (let i = 0; i < croakOfFrogs.length; i++) {
        if (croakOfFrogs[i] === 'c') {
            if (finishedCount > 0) {
                maxCount--;
                finishedCount--;
            }
            c--;
        } else if (croakOfFrogs[i] === 'r') {
            r--
        } else if (croakOfFrogs[i] === 'o') {
            o--
        } else if (croakOfFrogs[i] === 'a') {
            a--
        } else if (croakOfFrogs[i] === 'k') {
            k--
            finishedCount++;
        } else {
            return -1
        }
        if (c === -1 || r === -1 || o === -1 || a === -1 || k === -1) {
            return -1
        }
        if (c > r || r > o || o > a || a > k) {
            return -1
        }
    }

    return maxCount;
};