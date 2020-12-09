struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
 	
  struct ListNode* p;
  struct ListNode* q;
  struct ListNode* r;
	p=list1;
	q=list1;
	for(int i=1;i<a;++i)
	   p=p->next;
	for(int i=1;i<=b+1;++i) 
	   q=q->next;
        r=list2;
	while(r->next!=NULL)
	   r=r->next;
	   p->next=list2;
	   r->next=q;
	
	   
	return list1;

}

>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
    	string tmp;
    	int count=0;
    	int mcount=0;
    	int start=0;
        if(sequence==word)  return 1;
		while(start+word.size()<=sequence.size()){
			tmp=sequence.substr(start,word.size());
			if(tmp==word){
				count++;
				start=start+word.size();
				cout<<start<<endl;
			}
		    else{
		    
		    	if(count>mcount){
		    		mcount=count;
				}
		    
		    	count=0;
				start=start+1;
			}
		}
		if(count>mcount){
    		mcount=count;
		}
	return mcount; 
    }
};


class Solution {
public:
    bool hasCycle(ListNode *head) {
       unordered_set<ListNode*>meen;
       while(head!=NULL){
       	if(meen.count(head)) return true;
       	   meen.insert(head);
       	   head=head->next;     	
        }
     return false;   
    }
};
