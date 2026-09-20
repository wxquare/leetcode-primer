struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
    bool e(TreeNode* a, TreeNode* b) {
        return !a && !b || a && b && a->val == b->val && e(a->l, b->l) && e(a->r, b->r);
    }

public:
    bool isSubtree(TreeNode* r, TreeNode* s) {
        return s == 0 || r && (e(r, s) || isSubtree(r->l, s) || isSubtree(r->r, s));
    }
};
#define left l
#define right r
