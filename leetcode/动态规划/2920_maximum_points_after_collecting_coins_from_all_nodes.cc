#include <vector>
#include <algorithm>
using namespace std;
class Solution { vector<vector<int> > g; vector<int> c; int k; int dfs(int u,int p,int d){int keep=c[u]>>d,halve=c[u]-k;for(int v:g[u])if(v!=p){keep+=dfs(v,u,d);halve+=dfs(v,u,d+1);}return max(keep,halve);} public:int maximumPoints(vector<vector<int>>& edges,vector<int>& coins,int K){c=coins;k=K;g.assign(c.size(),vector<int>());for(auto&e:edges){g[e[0]].push_back(e[1]);g[e[1]].push_back(e[0]);}return dfs(0,-1,0);} };
