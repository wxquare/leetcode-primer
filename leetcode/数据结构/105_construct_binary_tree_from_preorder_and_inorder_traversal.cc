#include <vector>
#include <unordered_map>
using namespace std; struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{unordered_map<int,int>m;vector<int>*p;TreeNode*f(int a,int b,int l,int r){if(a>=b)return 0;int k=m[(*p)[a]];TreeNode*q=new TreeNode((*p)[a]);q->l=f(a+1,a+1+k-l,l,k);q->r=f(a+1+k-l,b,k+1,r);return q;}public:TreeNode* buildTree(vector<int>&pre,vector<int>&in){p=&pre;for(int i=0;i<in.size();i++)m[in[i]]=i;return f(0,pre.size(),0,in.size());}};
