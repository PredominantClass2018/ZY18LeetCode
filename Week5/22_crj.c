===================合并链表
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *p=list1,*q=list1;
    int i,j;
    for(i=0;i<a-1;i++)
    {
        p=p->next;
    }
    
    for(j=0;j<b+1;j++)
    {
        q=q->next;
    }
    p->next=list2;
    while(p->next)
    {
        p=p->next;
    }
    p->next=q;
    return list1;
}
======================== 最大重复子字符串（python）
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        n = len(sequence) // len(word)  # 最大循环节个数（向下取整）
        while n * word not in sequence:
            n -= 1
        return n
========================环形链表
bool hasCycle(struct ListNode* head) {
   if(head==NULL||head->next==NULL)
   {
       return false;
   }
   struct ListNode *fast;
   struct ListNode *slow;
   fast=head->next;
   slow=head;
   while(fast!=slow)
   {
       if(fast==NULL||fast->next==NULL)
       {
           return false;
       }
       fast=fast->next->next;
       slow=slow->next;
   }
   return true;
}