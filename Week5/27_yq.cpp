1

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* p1=list1, *p2=list2, *start=list1;
    for(int i=0;p1 && i<b+1;i++)
    {   if(i==a-1) start=p1;      //接入点的起点
        p1=p1->next;               //接入点的终点
    }
    start->next=list2;             //list2头部接入list1接入点的起点
    while(p2 && p2->next)
    {
        p2=p2->next;
    }
    if(p2)
    {
        p2->next=p1;            //list2的尾部接入list1接入点的终点
    }
    return list1;
}


2
int maxRepeating(char * sequence, char * word){
    int l1=strlen(sequence),l2=strlen(word);
    int count=0,mc=0;
    int i=0;
    
    if((sequence==NULL) || (word==NULL))    return 0;
    if(l1<l2)   return 0;
    
    while(i<=l1-l2)
    {
        if(strncmp(&sequence[i],word,l2)==0)
        {
            count=count+1;
            i=i+l2;
        }
        else
        {   count=0;
            i++;
        }
      if(mc<count) mc=count;
    }
    return mc;
}

3
bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)
        return false;
    struct ListNode *fast=head->next;
    struct ListNode *slow=head;
    while(fast!=slow)
    {
        if(fast==NULL || fast->next==NULL)
            return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;  
}


