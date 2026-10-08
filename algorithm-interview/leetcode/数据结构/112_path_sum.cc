struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* r, int t) {
        return r && (r->l || r->r ? hasPathSum(r->l, t - r->val) || hasPathSum(r->r, t - r->val)
                                  : r->val == t);
    }
};
