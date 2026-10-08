#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
    int ans = -1e9;
    int f(TreeNode* r) {
        if (!r) return 0;
        int a = max(0, f(r->left)), b = max(0, f(r->right));
        ans = max(ans, r->val + a + b);
        return r->val + max(a, b);
    }

public:
    int maxPathSum(TreeNode* r) {
        f(r);
        return ans;
    }
};
