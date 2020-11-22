



//1025
class Solution {
public:
    bool divisorGame(int N) {
        if(N%2==0) return true;
        else return false;
    }
};
//5
// // �����ⷨ
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

// //������չ��
// /*˼·
// ��babadΪ��
// ���ڻ��Ĵ��ǹ������ĶԳƵģ��������������˼����д�����
// ��������left��rightָ�룬����ָ���Ե�ǰλ�ü�iΪ���ĵ�����
// ���統ǰi=1ʱ��left��right�ĳ�ʼֵΪ1  1
// ��ȥjudge�������ж��Ƿ�Խ���Լ��Ƿ������������
// ��ȵĻ��ڱȽ���һ��
// ����Ⱦͷ��ص�ǰ���ϵ�����Ԫ�ظ���
// ��main������ͨ��ѭ���������ж�
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
//         //�˳�ѭ����left��right�м�Ĳ���Ϊ�����Ӵ�
//         return right-left-1;
//     }
// };

//��̬�滮
/*
���������м�
ʵ����������дһ�Ŷ�ά���
��Ҫ˼�룺�ڶԳƵ��ַ������˼��϶ԳƵ�����Ԫ�أ������γɵ��ַ���һ���ǻ��Ĵ�
״̬��dp[i][j]��ʾ�Ӵ�S[i...j]�Ƿ�Ϊ���Ĵ�
״̬ת�Ʒ��̣�dp[i][j]=(s[i]==s[j])and dp[i+1][j-1]
�߽�������dp[i+1][j-1]���Ľ��������i+1��j-1�ĸ���Ϊ0��1����<2
        ��j-1��-��i+1��+1<2       j-i<3
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
//���鼯�㷨
class Solution {
public: vector<int> fathers;
        vector<int> ranks;
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        if(n==0) return 0;
        for(int i=0;i<n;i++){//�Ƚ�ÿһ������һ��Ⱥ��
            fathers.push_back(i);
            ranks.push_back(1);
        }
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(M[i][j]==1) connect(i,j);//���������ڵ�������һ��
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
            fathers[f2]=f1;//��2����1��
            ranks[f1]++;
        }else if(ranks[f2]>ranks[f1]){
            fathers[f1]=f2;
        }else{
            fathers[f2]=f1;//��Ϊ1�Ľ��Ƚ���
        }
    }
};

