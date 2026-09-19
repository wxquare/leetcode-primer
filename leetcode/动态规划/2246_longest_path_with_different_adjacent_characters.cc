#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution { vector<vector<int> > g; string s; int ans; int dfs(int u){int a=0,b=0;for(int v:g[u]){int x=dfs(v);if(s[v]==s[u])continue;if(x>a)b=a,a=x;else if(x>b)b=x;}ans=max(ans,a+b+1);return a+1;} public:int longestPath(vector<int>& parent,string str){s=str;g.assign(s.size(),vector<int>());for(int i=1;i<(int)parent.size();++i)g[parent[i]].push_back(i);ans=0;dfs(0);return ans;} };
