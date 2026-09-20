#define left l
#define right r
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
public:
    vector<int> rightSideView(TreeNode* r) {
        vector<int> z;
        if (!r) return z;
        queue<TreeNode*> q;
        q.push(r);
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                auto* x = q.front();
                q.pop();
                if (!n) z.push_back(x->val);
                if (x->left) q.push(x->left);
                if (x->right) q.push(x->right);
            }
        }
        return z;
    }
};
#define left l
#define right r
