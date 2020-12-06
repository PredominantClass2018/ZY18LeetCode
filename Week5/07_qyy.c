struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int count=0;
    struct ListNode* mid_cur=list1;
    struct ListNode* mid_pre;
    while(mid_cur)
    {
        if(count+1==a)
            mid_pre=mid_cur;
        if(count-1==b)
            break;
        count++;
        mid_cur=mid_cur->next;
    }
    mid_pre->next=list2;
    while(list2->next)
    {
        list2=list2->next;
    }
    list2->next=mid_cur;
    return list1;
}

int maxRepeating(char * sequence, char * word){
int seqLen = strlen(sequence);
int wordLen = strlen(word);

if (seqLen < wordLen) return 0;

int maxCnt = 0;
int curCnt = 0;
for (int i = 0; i <= seqLen - wordLen; ) {
    if (strncmp(&sequence[i], word, wordLen) == 0) 
    {
        curCnt++;
        i += wordLen;
    } 
    else 
    {
        curCnt = 0;
        i++;
    }

    if (curCnt > maxCnt) 
    {
        maxCnt = curCnt;
    }
}
return maxCnt;
}


bool hasCycle(struct ListNode *head) {
    if(!head)
        return 0;
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)  return 1;
    }
    return 0;
}
