https://leetcode-cn.com/problems/longest-well-performing-interval/

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        if(hours.size()==0) return 0;
        vector <int> score(hours.size(),0) ;
        int ans=0;
        for(int i=0;i<hours.size();i++)
        {
            if(hours[i]>8)  score[i]=1;
            else    score[i]=-1;
        }
        vector <int> pres(hours.size()+1,0);    //前缀和数组
        pres[0]=0;
        for(int i=0;i<hours.size();i++)
            pres[i+1]=pres[i]+score[i];
        //顺序生成单调栈，栈中从第一个元素开始严格单调递减，最后一个元素一定是数组中最小元素所在位置
        stack <int> stk;
        stk.push(0);
        for(int i=0;i<hours.size();i++)
        {
            if(pres[i]<pres[stk.top()]) stk.push(i);
        }
        for(int i=hours.size();i>=0 && !stk.empty(); --i)
        {
            while(!stk.empty() && pres[i]>pres[stk.top()])
            {
                ans=max(ans,i-stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};

https://leetcode-cn.com/problems/minimum-number-of-frogs-croaking/

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        int count=0;
        int c=0;    int r=0;   int o=0;   int a=0;   int k=0;
        bool flag=true;
        for(int i=0;i<croakOfFrogs.size();i++)
        {   
            if(croakOfFrogs[i]=='c') c++;
            if(croakOfFrogs[i]=='r') r++;
            if(croakOfFrogs[i]=='o') o++;
            if(croakOfFrogs[i]=='a') a++;
            count=max(count,c);
            if(croakOfFrogs[i]=='k')
            {
                k++;   
                if(c>=r && r>=o && o>=a && a>=k)
                {
                    c--;    r--;    o--;    a--;    k--;
                } 
                
            }
            if(!( c>=r && r>=o && o>=a && a>=k))
            {
                     flag=false;
                     break;
            }
        }
       
        if(c!=0 || r!=0 || o!=0 || a!=0 || k!=0)    flag=false;
        if(flag==true) return count;
        else return -1;
    }
};