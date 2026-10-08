struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(0) {}
};
class Solution {
public:
    bool hasCycle(ListNode* h) {
        ListNode *a = h, *b = h;
        while (b && b->next) {
            a = a->next;
            b = b->next->next;
            if (a == b) return true;
        }
        return false;
    }
};
