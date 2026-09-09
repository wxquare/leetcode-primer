#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        function<int(TreeNode*,TreeNode*&)> dfs = [&](TreeNode* rt,TreeNode *&lca)-> int{
            if(rt == nullptr) return 0;

            std::cout << rt->val << std::endl;
            if(!rt->left && !rt->right){
                lca = rt;
                return 1;
            }
            TreeNode* lcaLeft;
            int dl = dfs(rt->left,lcaLeft);

            TreeNode* lcaRight;
            int dr = dfs(rt->right,lcaRight);

            if(dl == dr){
                lca = rt;
            }else if (dl > dr){
                lca = lcaLeft;
            }else if(dl < dr){
                lca = lcaRight;
            }
            return max(dl,dr) + 1;
        };

        TreeNode* ans;
        dfs(root,ans);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode* n0 = new TreeNode(0);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n2 = new TreeNode(2);
    TreeNode* n3 = new TreeNode(3);

    n0->left = n1;
    n1->right = n2;
    n0->right = n3;

    std::cout << n0->val << std::endl;

    

    std::cout << Solution().lcaDeepestLeaves(n0)->val << std::endl;


    std::cout << n0->val << std::endl;
    std::cout << n1->val << std::endl;
    std::cout << n2->val << std::endl;
    std::cout << n3->val << std::endl;


    return 0;
}
