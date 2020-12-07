//1669. 合并两个链表

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
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
}



//1668. 最大重复子字符串

int maxRepeating(char * sequence, char * word){
    int len_w = strlen(word);
    int len_s = strlen(sequence);
    int count = 0, a = 0; 
    int b = 0;
    int max = -1;

    for(int i = 0; i < len_s; i++) {
        for(int j = 0; j < len_w; j++) {
            if(sequence[i + j] == word[j]) {
                a++;
                if(a == len_w) {
                    if(b == 1) {
                        b = 0;
                        count = 0;
                    }
                    count++;
                    a = 0;
                    i += j;
                    if(max < count) max = count;
                }
            }
            else {
                a = 0;
                b = 1;
                if(max < count) {
                    max = count;
                }
                break;
            }
        }
    }        

    return max;
}


//141. 环形链表

bool hasCycle(struct ListNode *head) {
    struct ListNode *Addr[10000]={0};
    short i=0,j;
    while(head!=0){
        for(j=0;j<10000;j++)
            if(head==Addr[j]) return 1;
        Addr[i]=head;
        head=head->next;
        i++;
    }
    return 0;
}
 
