//1669

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode *fast = list1;
    struct ListNode *slow =  list1;
    struct ListNode *temp = list2;
    for(int i =0;i<b+1;i++)
    {
        fast = fast->next;
    }
    for(int i = 0;i<a-1;i++)
    {
        slow = slow->next;
    }
    slow->next = list2;
    
    while((temp !=NULL) && (temp->next != NULL))
    {
        temp = temp->next;
    }
    temp->next = fast;
    return list1;
}





//1668

int maxRepeating(char * sequence, char * word){
    /*
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
        */
        if ((sequence == NULL) || (word == NULL)) return 0;

int seqLen = strlen(sequence);
int wordLen = strlen(word);

if (seqLen < wordLen) return 0;

int maxCnt = 0;
int curCnt = 0;
for (int i = 0; i <= seqLen - wordLen; ) {
    if (strncmp(&sequence[i], word, wordLen) == 0) {
        curCnt++;
        i += wordLen;
    } else {
        curCnt = 0;
        i++;
    }

    if (curCnt > maxCnt) {
        maxCnt = curCnt;
    }
}
return maxCnt;
}




//141

 /*
struct hashTable {
    struct ListNode* key;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(struct ListNode* ikey) {
    struct hashTable* tmp;
    HASH_FIND_PTR(hashtable, &ikey, tmp);
    return tmp;
}

void insert(struct ListNode* ikey) {
    struct hashTable* tmp = malloc(sizeof(struct hashTable));
    tmp->key = ikey;
    HASH_ADD_PTR(hashtable, key, tmp);
}

bool hasCycle(struct ListNode* head) {
    hashtable = NULL;
    while (head != NULL) {
        if (find(head) != NULL) {
            return true;
        }
        insert(head);
        head = head->next;
    }
    return false;
}
*/

bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}