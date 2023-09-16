/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int> m;
    int rob(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        if(m.count(root)){
            return m[root];
        }

        // 不选root
        int left = rob(root->left);
        int right = rob(root->right);
        int no = left + right;

        // 选root
        int yes = root->val;
        if(root->left){
            yes += rob(root->left->left) + rob(root->left->right);
        }
        if(root->right){
            yes += rob(root->right->left) + rob(root->right->right);
        }
        int ans = max(yes,no);
        m[root] = ans;
        return ans;
    }
};