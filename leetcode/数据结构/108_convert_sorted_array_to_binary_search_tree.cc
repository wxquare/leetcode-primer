#define left l
#define right r
#include <vector>
using namespace std; struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{TreeNode*f(vector<int>&a,int l,int r){if(l>=r)return 0;int m=(l+r)/2;TreeNode*x=new TreeNode(a[m]);x->l=f(a,l,m);x->r=f(a,m+1,r);return x;}public:TreeNode* sortedArrayToBST(vector<int>&a){return f(a,0,a.size());}};
#define left l
#define right r
