#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(0), right(0) {}
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
    vector<vector<TreeNode*>> memo;

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        memo.resize(n + 1);
        if (!(n & 1)) return vector<TreeNode*>();
        if (n == 1) return vector<TreeNode*>(1, new TreeNode(0));
        if (!memo[n].empty()) return memo[n];
        for (int l = 1; l < n; l += 2)
            for (TreeNode* a : allPossibleFBT(l))
                for (TreeNode* b : allPossibleFBT(n - 1 - l)) {
                    TreeNode* r = new TreeNode(0);
                    r->left = a;
                    r->right = b;
                    memo[n].push_back(r);
                }
        return memo[n];
    }
};
