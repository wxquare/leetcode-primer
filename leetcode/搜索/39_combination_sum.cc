#include <algorithm>
#include <vector>
using namespace std;
class Solution { void dfs(int p,int target,vector<int>& c,vector<int>& cur,vector<vector<int> >& out){if(!target){out.push_back(cur);return;} for(int i=p;i<(int)c.size()&&c[i]<=target;++i){cur.push_back(c[i]);dfs(i,target-c[i],c,cur,out);cur.pop_back();}} public: vector<vector<int> > combinationSum(vector<int>& candidates,int target){sort(candidates.begin(),candidates.end());vector<vector<int> > out;vector<int> cur;dfs(0,target,candidates,cur,out);return out;} };
