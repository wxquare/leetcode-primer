struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
    int f(TreeNode* r, int x) {
        if (!r) return 0;
        x = x * 10 + r->val;
        return r->l || r->r ? f(r->l, x) + f(r->r, x) : x;
    }

public:
    int sumNumbers(TreeNode* r) { return f(r, 0); }
};
#define left l
#define right r
