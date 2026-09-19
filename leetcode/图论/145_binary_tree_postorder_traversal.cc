#include <vector>
#include <stack>
#include <algorithm>
using namespace std; struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(0),right(0){}}; class Solution{public:vector<int>postorderTraversal(TreeNode*r){vector<int>o;stack<TreeNode*>s;if(r)s.push(r);while(!s.empty()){r=s.top();s.pop();o.push_back(r->val);if(r->left)s.push(r->left);if(r->right)s.push(r->right);}reverse(o.begin(),o.end());return o;}};
