struct TreeNode { int val; TreeNode* left; TreeNode* right; TreeNode(int x):val(x),left(0),right(0){} };
class Solution { public:bool hasPathSum(TreeNode*root,int targetSum){if(!root)return false;if(!root->left&&!root->right)return targetSum==root->val;return hasPathSum(root->left,targetSum-root->val)||hasPathSum(root->right,targetSum-root->val);} };
