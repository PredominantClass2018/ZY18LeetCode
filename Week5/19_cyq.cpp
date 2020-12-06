class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k=0;
        string sub;
        while(k*word.size()<=sequence.size()){
            sub+=word;
            if(sequence.find(sub)!=string::npos){
                ++k;
            }
            else break;
        }
        return k;
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr) return false;
        ListNode* fast;
        ListNode* slow;
        slow=head;
        fast=head->next;
        while(fast!=slow){
            if(fast==nullptr||fast->next==nullptr) return false;
            fast=fast->next->next;
            slow=slow->next;
        }
        return true;
    }
};


class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *list;
        list=list1;
        while(list->next->val!=a){
            list=list->next;
        }
        ListNode* end1;
        end1=list;
        while(list->val!=b){
            list=list->next;
        }
        list=list->next;
        end1->next=list2;
        ListNode *end2;
        end2=list2;
        while(end2->next){
            end2=end2->next;
        }
        end2->next=list;
        return list1;
    }
};
