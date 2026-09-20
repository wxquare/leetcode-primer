struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(0) {}
};
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* h) {
        ListNode d(0);
        d.next = h;
        ListNode* p = &d;
        while (p->next) {
            ListNode* q = p->next;
            while (q->next && q->next->val == q->val) q = q->next;
            if (q != p->next) p->next = q->next;
            else p = p->next;
        }
        return d.next;
    }
};
