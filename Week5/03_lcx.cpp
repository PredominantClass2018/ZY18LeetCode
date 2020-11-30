//LeetCode 141
//https://leetcode-cn.com/problems/linked-list-cycle/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
			return false;
		ListNode *p = head->next, *q = head;
		while(p && p->next){
			if(p == q)
				return true;
			p = p->next->next;
			q = q->next;
		}
		return false;
    }
};


//LeetCode 1668
//https://leetcode-cn.com/problems/maximum-repeating-substring/
class Solution {
private:
	int fun(const string& sequence, const string& word, int n) {
		int p = sequence.find(word, n);
		if (p == sequence.npos)
			return 0;
		int t = 1;
		p += word.size();
		while (p + word.size() <= sequence.size() && word == string(sequence.begin() + p, sequence.begin() + p + word.size())) {
			++t;
			p += word.size();
		}
		return max(t, fun(sequence, word, p));
	}
public:
	int maxRepeating(string sequence, string word) {
		return fun(sequence, word, 0);
	}
};


//LeetCode 1669
//https://leetcode-cn.com/problems/merge-in-between-linked-lists/
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p1 = list1, *p2 = list1, *q = list2;
		for(int i = 1; i < a; ++i)
			p1 = p1->next;
		p2 = p1->next;
		for(int i = a - 1; i < b; ++i)
			p2 = p2->next;
		while(q->next)
			q = q->next;
		p1->next = list2;
		q->next = p2;
		return list1;
    }
};
