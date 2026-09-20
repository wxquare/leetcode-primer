#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
    bool f(TreeNode* a, TreeNode* b) {
        return !a && !b || (a && b && a->val == b->val && f(a->l, b->r) && f(a->r, b->l));
    }

public:
    bool isSymmetric(TreeNode* r) { return f(r, r); }
};
