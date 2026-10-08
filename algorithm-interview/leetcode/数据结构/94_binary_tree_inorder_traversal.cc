#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
    void f(TreeNode* r, vector<int>& a) {
        if (!r) return;
        f(r->left, a);
        a.push_back(r->val);
        f(r->right, a);
    }

public:
    vector<int> inorderTraversal(TreeNode* r) {
        vector<int> a;
        f(r, a);
        return a;
    }
};
