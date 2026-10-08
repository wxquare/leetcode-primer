#include <vector>
#include <unordered_set>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
    bool f(TreeNode* r, int k, unordered_set<int>& s) {
        if (!r) return false;
        if (s.count(k - r->val)) return true;
        s.insert(r->val);
        return f(r->left, k, s) || f(r->right, k, s);
    }

public:
    bool findTarget(TreeNode* r, int k) {
        unordered_set<int> s;
        return f(r, k, s);
    }
};
