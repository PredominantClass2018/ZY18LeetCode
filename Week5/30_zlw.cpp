

#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    Solution() = default;

public:
    
    //1668. 最大重复子字符串
    //https://leetcode-cn.com/problems/maximum-repeating-substring/
    
    int maxRepeating(string sequence, string word) {
       int len1 = sequence.length();
       int len2 = word.length();
       if (len1 == 0 || len2 == 0 || len2 > len1)
           return 0;
       
       int k = 0;  //重复次数
       int i = 0;
       int max_k = 0;

       while (i <= len1 - len2)
       {
           if (sequence.substr(i, len2) == word)
           {
               ++k;
               i += len2;
               max_k = k > max_k ? k : max_k;
           }
           else {              
               k = 0;
               ++i;
           }         
       }
       return max_k;
    }

    /*
    1669. 合并两个链表
    https://leetcode-cn.com/problems/merge-in-between-linked-lists/
    */
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int pos = 0;
        ListNode* iter1 = list1;
        while (pos < a - 1)
        {
            iter1 = iter1->next;
            ++pos;
        }//现在iter1指向第a-1个位置



        ListNode* iter2 = iter1;
        while (pos < b)
        {
            iter2 = iter2->next;
            ++pos;
        }//现在iter2指向第b个位置


        iter1->next = list2;

        ListNode* iter3 = list2;
        while (iter3->next != NULL)
        {
            iter3 = iter3->next;
        }//现在iter3指向iter2的末尾

        iter3->next = iter2->next;

        return list1;
    }

    //141.环形链表 判断链表中是否有环 
    //https://leetcode-cn.com/problems/linked-list-cycle/
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return false;
        ListNode* pos;
        int i = 0;
        for (pos = head; pos != NULL;)
        {
            pos->val = i++;
            if (pos->next != NULL && pos->val > pos->next->val)
                return true;
            pos = pos->next;
        }
        return false;
    }
};

int main(void)
{
  
 

    Solution s = Solution();
  
   
    return 0;
}