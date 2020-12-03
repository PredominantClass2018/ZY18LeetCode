//1669
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* front = list2, * rear = list2;
        ListNode* pre = list1;
        int count = 0;
        while (rear->next != NULL) {
            rear = rear->next;
        }
        while (pre) {
            count++;
            if (count == a) {
                ListNode* t = pre->next;
                pre->next = front;
                pre = t;
                count++;
            }
            if (count == b + 1) {
                rear->next = pre->next;
                break;
            }
            pre = pre->next;
        }
        return list1;
    }
};
//1668
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int i = 0, j = 0;
        int max = 0, count = 0;
        int f[100];
        memset(f, -1, sizeof(f));
        while (i < sequence.size()) {
            while (i + j < sequence.size() && sequence[i + j] == word[j]) {
                j++;
                if (j == word.size()) {
                    count++;
                    if (count > max) {
                        max = count;
                    }
                    i = i + j;
                    f[i - 1] = max;
                    j = 0;
                }
            }
            count = 0;
            i = i + 1;
            j = 0;
        }
        return max;
    }
};
//141
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* fast = head->next, * slow = head;
        while (fast != slow) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};