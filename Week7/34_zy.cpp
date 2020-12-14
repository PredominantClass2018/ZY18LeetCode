//表现良好的最长时间段
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res=0;
        stack<int> s;
        s.push(0);
        vector<int> sum(hours.size()+1);
        for(int i=0;i<hours.size();i++)
        {
            sum[i+1]=hours[i]>8?sum[i]+1:sum[i]-1;
            if(s.empty()||sum[s.top()]>sum[i+1]) s.push(i+1);
        }
        for(int i=sum.size()-1;i>=0;i--)
        {
            while(s.size()&&sum[i]>sum[s.top()]){
                res=max(res,i-s.top());
                s.pop();
            }
        }
        return res;
    }
};
//数青蛙
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int c = 0, r = 0, o = 0, a = 0, k = 0, Max = 0;
        for(char x:croakOfFrogs) {
            if(x == 'c') ++c;
            else if(x == 'r') ++r;
            else if(x == 'o') ++o;
            else if(x == 'a') ++a;
            else if(x == 'k') ++k;
            else return -1;
            if(r > c || o > r || a > o || k > a) return -1;
            if(k == 1) {
                --c;
                --r;
                --o;
                --a;
                --k;
            }
            Max = max(Max, c);
        }
        if(c) return -1;
        return Max;
    }
};