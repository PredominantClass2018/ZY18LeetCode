https://leetcode-cn.com/problems/complex-number-multiplication/

class Solution {
public:
    void splitComplex(stringstream& ss,int& a, int& b)
    {
        char plus;
        ss >> a >> plus >>b;
    }
    string complexNumberMultiply(string a, string b) {
        int x1,y1;
        stringstream ss1(a);
        splitComplex(ss1,x1,y1);
        
        int x2,y2;
        stringstream ss2(b);
        splitComplex(ss2,x2,y2);
        
        int real = x1*x2-y1*y2;
        int imag = x1*y2+x2*y1;
        
        return to_string(real) + "+" + to_string(imag) + "i"; 
    }
};

https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=nums.size();
        if(l==1) return nums[0];
        for(int i=0;i<l;i++)
        {
            if(nums[i]<nums[0])
            {
                return nums[i];
                break;
            }
        }
        return nums[0] ;
    }
    

};
