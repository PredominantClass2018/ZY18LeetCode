//141
class Solution {
    /*
    快慢指针
    */
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(slow!=fast){
            if(fast==NULL || fast->next==NULL) return false;
            else{
                slow=slow->next;
                fast=fast->next->next;
            }
        }
        return true;
    }
};

//1669
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //找到a
        ListNode *pre=list1;
        for(int i=0;i<a-1;i++){
            pre=pre->next;
        }
        ListNode *net=list1;
        for(int i=0;i<b;i++){
            net=net->next;
        }
        //删除
        pre->next=net->next;
        //插入list2
        ListNode * k=list2;
        while(k->next != nullptr){
            k=k->next;
        }
        k->next=pre->next;
        pre->next=list2;
        return list1;
    }
};

//1668
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        int val=0;

        int i=0,j=0;
        int index=0;
        while(i < sequence.size()){
            if(sequence.at(i)==word.at(j)){
                i++;
                j++;
                if(j==word.size()){
                    count++;
                    j=0;
                }
            }else{
                if(count!=0){
                    val=max(count,val);
                }
                i=++index;
                j=0;
                count=0;
            }
        }
        val=max(count,val);
        return val;
    }
};