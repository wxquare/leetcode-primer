#include <vector>
using namespace std;
class Solution { void dfs(int next,int n,int left,vector<int>& cur,vector<vector<int> >& out){if(!left){out.push_back(cur);return;} for(int i=next;i<=n-left+1;++i){cur.push_back(i);dfs(i+1,n,left-1,cur,out);cur.pop_back();}} public: vector<vector<int> > combine(int n,int k){vector<vector<int> > out;vector<int> cur;dfs(1,n,k,cur,out);return out;} };
