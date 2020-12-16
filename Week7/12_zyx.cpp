//1124
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> m;
        for (int i = 0; i < hours.size(); i++) {
            hours[i] = hours[i] > 8 ? 1 : -1;
            sum = sum + hours[i];
            if (sum > 0) {
                ans = i + 1;
            }
            else if (m.count(sum - 1)) {
                ans = max(ans, i - m[sum - 1]);
            }
            if (!m.count(sum) && sum < 0) {
                m[sum] = i;
            }
        }
        return ans;
    }
};
//1419
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count = 0, countc = 0, countr = 0, counto = 0, counta = 0, countk = 0, max = 0;
        for (int i = 0; i < croakOfFrogs.size(); i++) {
            if (croakOfFrogs[i] == 'c') {
                countc++;
                count++;
                if (max < count) {
                    max = count;
                }
            }
            else if (croakOfFrogs[i] == 'r') {
                if (countr < countc) {
                    countr++;
                }
                else {
                    return -1;
                }
            }
            else if (croakOfFrogs[i] == 'o') {
                if (counto < countr && counto < countc) {
                    counto++;
                }
                else {
                    return -1;
                }
            }
            else if (croakOfFrogs[i] == 'a') {
                if (counta < counto && counta < countr && counta < countc) {
                    counta++;
                }
                else {
                    return -1;
                }
            }
            else {
                if (countk < counta && countk < counto && countk < countr && countk < countc) {
                    countc--;
                    countr--;
                    counto--;
                    counta--;
                    count--;
                }
                else {
                    return -1;
                }
            }
        }
        if (countc == 0 && countr == 0 && counto == 0 && counta == 0 && countk == 0) {
            return max;
        }
        else {
            return -1;
        }
    }
};