#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};
class Solution {
    int ans;
    int dfs(TreeNode* x) {
        if (!x) return 0;
        int l = dfs(x->left), r = dfs(x->right), a = 0, b = 0;
        if (x->left && x->left->val == x->val) a = l + 1;
        if (x->right && x->right->val == x->val) b = r + 1;
        ans = max(ans, a + b);
        return max(a, b);
    }

public:
    int longestUnivaluePath(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
