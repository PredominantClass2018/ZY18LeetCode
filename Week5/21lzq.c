1669

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) {
    int i, j, k;
    struct ListNode* q, * p;
    q = list1;
    p = list2;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (b)
    {
        q = q->next;
        b--;
    }
    p->next = q->next;

    q = list1;
    while (a - 1)
    {
        q = q->next;
        a--;
    }
    q->next = list2;
    return list1;
}

1668
int maxRepeating(char* sequence, char* word) {
    int len_s = strlen(sequence);
    int len_w = strlen(word);
    int i, j, k = 0, max = 0;
    for (i = 0; i <= len_s - len_w; i++)
    {
        for (j = 0; j < len_w; j++) {
            if (sequence[j + i] != word[j])
            {
                k = 0;
                break;
            }
            if (j == len_w - 1)
            {
                k++;
                i = i + len_w - 1;
            }
            max = k > max ? k : max;
        }
    }
    return max;
}

141
bool hasCycle(struct ListNode* head) {
    struct ListNode* first, * second;
    first = second = head;
    while (first != NULL)
    {
        if (first->next == NULL || first->next->next == NULL)
            return 0;
        else first = first->next->next;
        second = second->next;
        if (first->val == second->val)
            return 1;

    }
    return 0;

}