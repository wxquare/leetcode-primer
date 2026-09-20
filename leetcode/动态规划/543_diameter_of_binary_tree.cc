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
        int l = dfs(x->left), r = dfs(x->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
