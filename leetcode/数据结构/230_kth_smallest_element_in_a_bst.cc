#define left l
#define right r
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *l, *r;
    TreeNode(int x) : val(x), l(0), r(0) {}
};
class Solution {
public:
    int kthSmallest(TreeNode* r, int k) {
        vector<TreeNode*> s;
        while (1) {
            while (r) s.push_back(r), r = r->l;
            r = s.back();
            s.pop_back();
            if (!--k) return r->val;
            r = r->r;
        }
    }
};
#define left l
#define right r
