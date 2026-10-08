#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(0), right(0) {}
};

class Solution {
    int answer;
    int previous;
    bool hasPrevious;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (hasPrevious) answer = min(answer, root->val - previous);
        previous = root->val;
        hasPrevious = true;
        inorder(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        answer = INT_MAX;
        previous = 0;
        hasPrevious = false;
        inorder(root);
        return answer;
    }
};
