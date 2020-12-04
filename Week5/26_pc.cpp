//1���ϲ���������
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *head;
        head = list1;
        //�ȶ�λ��a-1
        for(int i = 0; i < a-1; ++i){
            head = head->next;
        }
        ListNode *list1tail = head;
        //ɾ��a--b
        for (int j = a;j < b+2; ++j){
            head = head->next;
        }
        ListNode *list2head = head;
        //��list2׷�ӵ�a-1����
        list1tail->next = list2;
        ListNode *t = list2;
        while(t->next != nullptr)
            t = t->next;
        //��b�����׷�ӵ�list2����
        t->next = list2head;
        return list1;
    }
};

//2�����Ӵ�����
class Solution {
public:
    bool FindWord(string sequence, string  word){
        return (sequence.find(word) != string::npos);//npos��ʾstring�Ľ���
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

//3����������
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
