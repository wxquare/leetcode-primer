#include <algorithm>
#include <vector>
using namespace std;
class Solution { void dfs(int p,int target,vector<int>& a,vector<int>& cur,vector<vector<int> >& out){if(!target){out.push_back(cur);return;}for(int i=p;i<(int)a.size()&&a[i]<=target;++i){if(i>p&&a[i]==a[i-1])continue;cur.push_back(a[i]);dfs(i+1,target-a[i],a,cur,out);cur.pop_back();}} public:vector<vector<int> > combinationSum2(vector<int>& candidates,int target){sort(candidates.begin(),candidates.end());vector<vector<int> >out;vector<int>cur;dfs(0,target,candidates,cur,out);return out;} };
