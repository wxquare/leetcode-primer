#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
    void f(TreeNode* x, vector<int>& a) {
        if (!x) return;
        f(x->l, a);
        a.push_back(x->val);
        f(x->r, a);
    }

public:
    vector<int> inorderTraversal(TreeNode* r) {
        vector<int> a;
        f(r, a);
        return a;
    }
};
