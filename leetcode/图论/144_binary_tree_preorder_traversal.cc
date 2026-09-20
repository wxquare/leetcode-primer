#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* r) {
        vector<int> o;
        stack<TreeNode*> s;
        if (r) s.push(r);
        while (!s.empty()) {
            r = s.top();
            s.pop();
            o.push_back(r->val);
            if (r->right) s.push(r->right);
            if (r->left) s.push(r->left);
        }
        return o;
    }
};
