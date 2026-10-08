struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
public:
    void flatten(TreeNode* r) {
        if (!r) return;
        flatten(r->left);
        flatten(r->right);
        TreeNode* x = r->right;
        r->right = r->left;
        r->left = 0;
        TreeNode* p = r;
        while (p->right) p = p->right;
        p->right = x;
    }
};
