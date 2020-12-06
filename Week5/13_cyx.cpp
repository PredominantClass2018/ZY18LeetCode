1669. 合并两个链表
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
  struct ListNode* ptr1 = list1, *start = list1, *ptr2 = list2;
  for(int i = 0; i < b + 1 && ptr1; i++) {
    if(i == a - 1) {
      start = ptr1;
    } 
    ptr1 = ptr1->next;
  }
  while(ptr2 && ptr2->next) {
    ptr2 = ptr2->next;
  }
  if(ptr2) {
    ptr2->next = ptr1;
  } else {
    list2 = ptr1;
  }
  start->next = list2;
  return list1;
}
1668. 最大重复子字符串
int maxRepeating(char * sequence, char * word){
	int l1=strlen(sequence),l2=strlen(word);
	int count=0,i=0,m=0;
	if(l1<l2) return 0;
	if((l1==NULL)||(l2==NULL)) return 0;
	while(l1-l2>=i){
		if(strncmp(&sequence[i],word,l2)==0){
			count++;
			i=i+l2;
		}
		else{
			count=0;
			i++;
		}
		if(count>m) m=count;	
	}
	return m;

}
141. 环形链表
bool hasCycle(struct ListNode *head) {
	struct ListNode *q1=head;
	struct ListNode *q2=head;
	
	while(q1!=NULL){
		 if(q1->next!=NULL){
		 	q1=q1->next;
		 }
		 else return false;
		 
		 if(q1->next!=NULL){
		 	q1=q1->next;
		 }
		 else return false;
	     
		 q2=q2->next;
	     if(q2==q1) return true;		
	}
	return false;
	 
}
