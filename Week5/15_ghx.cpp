/*struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    int count = 0;
    struct ListNode* mid_cur = list1;
    struct ListNode* mid_pre;
    while(mid_cur){
        if(count+1==a){
            mid_pre = mid_cur;
        }
        if(count-1 == b){
            break;
        }
        count++;
        mid_cur = mid_cur->next;
    }
    mid_pre->next = list2;
    while(list2->next){
        list2 = list2->next;
    }
    list2->next = mid_cur;

    return list1;
}*/
int maxRepeating(char * sequence, char * word){
    int res = 0, L1 = strlen(sequence), L2 = strlen(word);
    for (int i = 0; i < L1; i++) {
        int j = i;  
        for (; j < L1 && sequence[j] == word[(j-i)%L2]; j++); 
        res = fmax(res, (j - i) / L2); 
    }
    return res;
}
/*int maxRepeating(char * sequence, char * word){
    int i;
    int L1=strlen(sequence);
    int L2=strlen(word);
    int max=0,mid=0;
    if(L1<L2) return 0;
    for(i=0;i<=L1-L2;){
       if(strncmp(&sequence[i],word,L2)==0){
           mid++;
           i+=L2;
       }
       else{
           mid=0;
           i++;
       }
       if(max<mid){
           max=mid;
        }
    }
    return max;
}*/
bool hasCycle(struct ListNode *head) {
    if(!head)
    return 0;
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while(fast&&fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow)
            return 1;
    }
    return 0;
}

