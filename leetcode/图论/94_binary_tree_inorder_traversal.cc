#include <vector>
#include <stack>
using namespace std; struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(0),right(0){}}; class Solution{public:vector<int>inorderTraversal(TreeNode*r){vector<int>o;stack<TreeNode*>s;while(r||!s.empty()){while(r)s.push(r),r=r->left;r=s.top();s.pop();o.push_back(r->val);r=r->right;}return o;}};
