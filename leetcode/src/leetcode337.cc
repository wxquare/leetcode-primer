/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。



输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7




方法一：动态规划
思路与算法

简化一下这个问题：一棵二叉树，树上的每个点都有对应的权值，每个点有两种状态（选中和不选中），问在不能同时选中有父子关系的点的情况下，能选中的点的最大权值和是多少。

我们可以用 f(o)f(o)f(o) 表示选择 ooo 节点的情况下，ooo 节点的子树上被选择的节点的最大权值和；g(o)g(o)g(o) 表示不选择 ooo 节点的情况下，ooo 节点的子树上被选择的节点的最大权值和；lll 和 rrr 代表 ooo 的左右孩子。

当 ooo 被选中时，ooo 的左右孩子都不能被选中，故 ooo 被选中情况下子树上被选中点的最大权值和为 lll 和 rrr 不被选中的最大权值和相加，即 f(o)=g(l)+g(r)f(o) = g(l) + g(r)f(o)=g(l)+g(r)。
当 ooo 不被选中时，ooo 的左右孩子可以被选中，也可以不被选中。对于 ooo 的某个具体的孩子 xxx，它对 ooo 的贡献是 xxx 被选中和不被选中情况下权值和的较大值。故 g(o)=max⁡{f(l),g(l)}+max⁡{f(r),g(r)}g(o) = \max \{ f(l) , g(l)\}+\max\{ f(r) , g(r) \}g(o)=max{f(l),g(l)}+max{f(r),g(r)}。
至此，我们可以用哈希表来存 fff 和 ggg 的函数值，用深度优先搜索的办法后序遍历这棵二叉树，我们就可以得到每一个节点的 fff 和 ggg。根节点的 fff 和 ggg 的最大值就是我们要找的答案。

我们不难给出这样的实现：

作者：力扣官方题解
链接：https://leetcode.cn/problems/house-robber-iii/solutions/361038/da-jia-jie-she-iii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。




class Solution {
public:
    unordered_map <TreeNode*, int> f, g;

    void dfs(TreeNode* node) {
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        f[node] = node->val + g[node->left] + g[node->right];
        g[node] = max(f[node->left], g[node->left]) + max(f[node->right], g[node->right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};

作者：力扣官方题解
链接：https://leetcode.cn/problems/house-robber-iii/solutions/361038/da-jia-jie-she-iii-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <vector>
#include <unordered_map>
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
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,vector<int>> dp;

        function<void(TreeNode*)> dfs = [&](TreeNode* cur){
            if(cur == nullptr) return;
            dfs(cur->left);
            dfs(cur->right);
            if(dp.count(cur) == 0){
                dp[cur] = vector<int>(2,0);
            }
            if(cur->left){
                dp[cur][0] += max(dp[cur->left][0],dp[cur->left][1]);
                dp[cur][1] += dp[cur->left][0];
            }
            if(cur->right){
                dp[cur][0] += max(dp[cur->right][0],dp[cur->right][1]);
                dp[cur][1] += dp[cur->right][0];
            }
            dp[cur][1] += cur->val;
        };
        dfs(root);
        return max(dp[root][0],dp[root][1]);   
    }
};

