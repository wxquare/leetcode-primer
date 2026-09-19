#define left l
#define right r
#include <vector>
#include <queue>
#include <algorithm>
using namespace std; struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{public:vector<vector<int>> zigzagLevelOrder(TreeNode*r){vector<vector<int>>z;if(!r)return z;queue<TreeNode*>q;q.push(r);bool rev=0;while(!q.empty()){vector<int>a;for(int n=q.size();n--;){auto*x=q.front();q.pop();a.push_back(x->val);if(x->left)q.push(x->left);if(x->right)q.push(x->right);}if(rev)reverse(a.begin(),a.end());rev=!rev;z.push_back(a);}return z;}};
#define left l
#define right r
