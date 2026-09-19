struct TreeNode{int val;TreeNode*l,*r;TreeNode(int x):val(x),l(0),r(0){}}; class Solution{int h(TreeNode*x){int n=0;while(x)n++,x=x->l;return n;}public:int countNodes(TreeNode*r){if(!r)return 0;int a=h(r->l),b=h(r->r);return a==b?(1<<a)+countNodes(r->r):(1<<b)+countNodes(r->l);}};
#define left l
#define right r
