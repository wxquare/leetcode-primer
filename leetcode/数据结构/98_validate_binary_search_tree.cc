#include <climits>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
    long long p = LLONG_MIN;
    bool f(TreeNode* r) { return !r || f(r->l) && r->val > p && (p = r->val) && f(r->r); }

public:
    bool isValidBST(TreeNode* r) { return f(r); }
};
#define left l
#define right r
