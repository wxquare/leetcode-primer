#include <vector>
using namespace std; struct TreeNode{int val;TreeNode*left,*right;TreeNode(int x):val(x),left(0),right(0){}}; class Solution{void f(TreeNode*r,vector<int>&a){if(!r)return;a.push_back(r->val);f(r->left,a);f(r->right,a);}public:vector<int> preorderTraversal(TreeNode*r){vector<int>a;f(r,a);return a;}};
