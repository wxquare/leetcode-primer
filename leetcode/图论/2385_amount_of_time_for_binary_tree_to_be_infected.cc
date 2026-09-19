#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
struct TreeNode{int val;TreeNode*left;TreeNode*right;TreeNode(int x):val(x),left(0),right(0){}};
class Solution { public:int amountOfTime(TreeNode*root,int start){unordered_map<int,vector<int>>g;queue<TreeNode*>nodes;nodes.push(root);while(!nodes.empty()){TreeNode*u=nodes.front();nodes.pop();if(u->left){g[u->val].push_back(u->left->val);g[u->left->val].push_back(u->val);nodes.push(u->left);}if(u->right){g[u->val].push_back(u->right->val);g[u->right->val].push_back(u->val);nodes.push(u->right);}}queue<int>q;q.push(start);unordered_set<int>seen;seen.insert(start);int minutes=-1;while(!q.empty()){int size=q.size();++minutes;while(size--){int u=q.front();q.pop();for(int v:g[u])if(seen.insert(v).second)q.push(v);}}return minutes;} };
