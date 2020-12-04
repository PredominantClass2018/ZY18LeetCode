//1、合并两个链表
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head;
        head = list1;
        //先定位到a-1
        for(int i = 0; i < a-1; ++i){
            head = head->next;
        }
        ListNode *list1tail = head;
        //删除a--b
        for (int j = a;j < b+2; ++j){
            head = head->next;
        }
        ListNode *list2head = head;
        //将list2追加到a-1后面
        list1tail->next = list2;
        ListNode *t = list2;
        while(t->next != nullptr)
            t = t->next;
        //将b后面的追加到list2后面
        t->next = list2head;
        return list1;
    }
};

//2、求子串个数
class Solution {
public:
    bool FindWord(string sequence, string  word){
        return (sequence.find(word) != string::npos);//npos表示string的结束
    }

    int maxRepeating(string sequence, string word) {
        string newword;
        int len = word.size();
        int count = 0;
        int wordnum =  0;
        while (wordnum*len <= sequence.size()){
            newword += word;
            if (FindWord(sequence,newword)){
                wordnum++;
                count = wordnum;
            }else{
                return wordnum;
            }
        }
        return count;
    }
};

//3、环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *pre = head;
        ListNode *cur = head;
        while(cur != NULL && cur->next != NULL){
            cur = cur->next->next;
            pre = pre->next;
            if(cur == pre)
                return true;
        }
        return false;
    }
};
