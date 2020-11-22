



//1025
class Solution {
public:
    bool divisorGame(int N) {
        if(N%2==0) return true;
        else return false;
    }
};
//5
// // 暴力解法
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n=s.size();
//         int begin=0,len=1;
//         vector<char>a;
//         if(n<2) return s;
//         else{
//             for(int i=0;i<n-1;i++){
//                 for(int j=i+1;j<n;j++){
//                     if((j-i+1>len)&&(bool_(s,i,j))){
//                         len=j-i+1;
//                         begin=i;
//                     }
//                 }
//             }
//         }
//         return s.substr(begin,len);
//     }
//      bool bool_(string s,int left,int right){
//         while((left<right)&&(left>=0)&&(right<s.size())){
//             if(s.at(left)!=s.at(right)) return false;
//             left++;
//             right--;
//         }
//         return true;
//     }
// };

// //中心扩展法
// /*思路
// 以babad为例
// 由于回文串是关于中心对称的，所以我们以这个思想来写这道题
// 我们设置left和right指针，用来指向以当前位置即i为中心的两边
// 例如当前i=1时，left和right的初始值为1  1
// 进去judge函数后，判断是否越界以及是否左右两边相等
// 相等的话在比较下一个
// 不相等就返回当前符合的数组元素个数
// 在main函数中通过循环来依次判断
// */
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n=s.size();
//         int max_s=0;
//         int start=0;
//         int len=0;
//         if(n==0) return{};
//         for(int i=0;i<n;i++){
//             len=max(judge(s,i,i),judge(s,i,i+1));
//             if(max_s < len){
//                 max_s=len;
//                 start=i-(max_s-1)/2;
//             }
//         }
//         return s.substr(start,max_s);
//     }
//     int judge(string s,int left,int right){
//         while(left>=0 && right<=s.size()-1 && s.at(left)==s.at(right)){
//             left--;
//             right++;
//         }
//         //退出循环后，left和right中间的部分为回文子串
//         return right-left-1;
//     }
// };

//动态规划
/*
从两边往中间
实际上是在填写一张二维表格
主要思想：在对称的字符串两端加上对称的两个元素，则新形成的字符串一定是回文串
状态：dp[i][j]表示子串S[i...j]是否为回文串
状态转移方程：dp[i][j]=(s[i]==s[j])and dp[i+1][j-1]
边界条件：dp[i+1][j-1]最后的结果就是在i+1与j-1的个数为0和1，即<2
        则（j-1）-（i+1）+1<2       j-i<3
*/
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n));
        if(n<2) return s;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int maxlen=1,start=0;

        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(s.at(i)!=s.at(j)){
                    dp[i][j]=false;
                }
                else{
                    if(j-i<3){
                        dp[i][j]=true;
                    }
                    else{
                        if(dp[i][j]=dp[i+1][j-1] &&(s.at(i)=s.at(j))){
                            dp[i][j]=true;
                        }
                    }
                }
                if(dp[i][j] && j - i + 1 > maxlen)  {
                    start = i;
                    maxlen = j - i + 1;  
                }  
            }
        }
        return s.substr(start,maxlen);
    }
};
//547
//并查集算法
class Solution {
public: vector<int> fathers;
        vector<int> ranks;
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){//先将每一个看成一个群体
            fathers.push_back(i);
            ranks.push_back(1);
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(M[i][j]==1) connect(i,j);//将两个父节点连接在一起
            }
        }
        int cout=0;
        for(int i=0;i<n;i++){
            if(fathers[i]==i){
                cout++;
            }
        }
        return cout;
    }
    int find(int i){
        int j=i;
        while(fathers.at(i)!=i){
            i=fathers[i];
        }
        while(fathers.at(j)!=i){
            fathers[j]=i;
        }
        return i;
    }
    void connect(int i,int j){
        int f1=find(i);
        int f2=find(j);
        if(ranks[f2]==ranks[f1]){
            fathers[f2]=f1;//将2挂在1上
            ranks[f1]++;
        }else if(ranks[f2]>ranks[f1]){
            fathers[f1]=f2;
        }else{
            fathers[f2]=f1;//因为1的结点比较深
        }
    }
};

