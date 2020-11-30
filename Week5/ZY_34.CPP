//合并两个链表
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* pNode = new ListNode;
        pNode->next = list1;//设置最后需要返回的虚拟节点，使其指向list1的首位
        ListNode* p1 = pNode;
        ListNode* p2 = list1;
        while(a--) p1 = p1->next;//找到a所在位置
        while(b--) p2 = p2->next;//找到b所在位置

        ListNode* p3 = list2;
        while(p3->next) p3 = p3->next;//找到待插入链表的末尾

        p1->next = list2;//将a所在位置的前一个元素指向待插入链表头部
        p3->next = p2->next;//将待插入指针的末尾指向b所在位置的后一个元素
        p2->next = nullptr;
        
        return pNode->next; 
    }
};
//最大重复子字符串
class Solution {
    public int maxRepeating(String sequence, String word) {
        int ans=0;
        String w=word;
        while(w.length() <= sequence.length() && sequence.contains(w))
        {
            ans++;
            w+=word;
        }
        return ans;
    }
}
//环形链表
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode*fast=head;
        ListNode*slow=head;
        //快慢指针相遇则说明一定有环
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)return true;
        }
        return false;
    }
};