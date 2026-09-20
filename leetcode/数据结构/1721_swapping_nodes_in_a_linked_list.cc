struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(0) {}
};
class Solution {
public:
    ListNode* swapNodes(ListNode* h, int k) {
        ListNode *a = h, *b = h;
        for (int i = 1; i < k; i++) a = a->next;
        ListNode* p = a;
        while (p->next) p = p->next, b = b->next;
        int t = a->val;
        a->val = b->val;
        b->val = t;
        return h;
    }
};
