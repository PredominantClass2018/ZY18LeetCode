
#include"iostream"
using namespace std;
 struct ListNode {
     int val;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* fa, * fa1, * b1;
        ListNode* end;
        end = List2;
        while (end->next!=NULL)
        {
            end = end->next;
        }
        fa1=fa = List1;
        b1 = List1;
        for (int i = 0; i < b; i++) {
            if (a == 1) {
                fa1 = List1;
            }else if (i == a-1) {
                fa1 = fa;
            }else {
                fa = fa->next;
            }
            b1 = b1->next;
        }
        if (b1->next == NULL) {
            fa1->next = list2;
        }
        else {
            end->next = b1->next;
            fa1->next = list2;
        }
        return list1;

    }
};
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int res = 0;
        int n = word.size();
        int curr = 0;
        string currstring;
        while (curr * n <= sequence.size()) {
            currstring += word;
            if (check(sequence, currstring)) {
                curr++;
                res = curr;
            }
            else {
                return curr;
            }
        }
        return res;
    }

    bool check(string sequence, string word) {
        return sequence.find(word) != string::npos;
    }
};
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode* p, * q;
        p = head;
        q = head;
        while (1) {
            q = q->next;
            p = p->next;
            if (q == NULL || p == NULL) return false;
            q = q->next;
            if (q == NULL || p == NULL) return false;
            if (q == p) return true;
        }
    }
};