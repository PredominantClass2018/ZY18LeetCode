1. 
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode* p=list1, *q;
    int i=b-a+1;
    while(--a) 
        p=p->next;
    q=p;
    while(i--) 
        q=q->next;
    p->next=list2;
    while(list2->next) 
        list2=list2->next;
    list2->next=q->next;
    return list1;
}



2.
int maxRepeating(char * sequence, char * word){
    int sl=strlen(sequence),wl=strlen(word);
    if(sl==0 || wl==0)  return 0;
    if(wl>sl)  return 0;
    int i=0,count=0,k=0;
    while(i<=sl){
        if(strncmp(&sequence[i],word,wl)==0){
            count=count+1;
            i=i+wl;
        }
        else{
            count=0;
            i++;
        }
        if(k<count) k=count;
    }
    return k;
}




3.
bool hasCycle(struct ListNode *head) {
    if(head==NULL || head->next==NULL)
        return false;    
    struct ListNode* fast=head->next;
    struct ListNode* slow=head;

    while(fast!=slow){
        if(fast==NULL || fast->next==NULL)
            return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    return true;
}

