#include <vector>
using namespace std;
class Solution { void dfs(int x,int k,int sum,vector<int>&cur,vector<vector<int> >&out){if(!k){if(!sum)out.push_back(cur);return;}for(int i=x;i<=9&&i<=sum;++i){cur.push_back(i);dfs(i+1,k-1,sum-i,cur,out);cur.pop_back();}} public:vector<vector<int> > combinationSum3(int k,int n){vector<vector<int> >out;vector<int>cur;dfs(1,k,n,cur,out);return out;} };
