#include <algorithm>
struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{public:int maxDepth(TreeNode*r){return r?1+std::max(maxDepth(r->l),maxDepth(r->r)):0;}};
