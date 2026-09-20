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
    vector<double> averageOfLevels(TreeNode* r) {
        vector<double> z;
        queue<TreeNode*> q;
        if (r) q.push(r);
        while (!q.empty()) {
            long s = 0, n = q.size();
            for (int i = 0; i < n; i++) {
                auto* x = q.front();
                q.pop();
                s += x->val;
                if (x->l) q.push(x->l);
                if (x->r) q.push(x->r);
            }
            z.push_back((double)s / n);
        }
        return z;
    }
};
#define left l
#define right r
