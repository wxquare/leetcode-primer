#include <vector>
#include <unordered_map>
using namespace std; struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{unordered_map<int,int>m;vector<int>*p;TreeNode*f(int l,int r,int a,int b){if(l>=r)return 0;int x=(*p)[b-1],k=m[x];TreeNode*n=new TreeNode(x);n->l=f(l,k,a,a+k-l);n->r=f(k+1,r,a+k-l,b-1);return n;}public:TreeNode* buildTree(vector<int>&in,vector<int>&post){p=&post;for(int i=0;i<in.size();i++)m[in[i]]=i;return f(0,in.size(),0,post.size());}};
