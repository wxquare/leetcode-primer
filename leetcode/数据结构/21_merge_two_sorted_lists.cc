struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(0) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode d(0), *p = &d;
        while (a && b) {
            if (a->val < b->val) p->next = a, a = a->next;
            else p->next = b, b = b->next;
            p = p->next;
        }
        p->next = a ? a : b;
        return d.next;
    }
};
