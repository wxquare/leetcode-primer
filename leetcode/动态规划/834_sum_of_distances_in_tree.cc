#include <vector>
using namespace std;
class Solution {vector<vector<int> >g;vector<int>sz,a;void d(int u,int p){sz[u]=1;for(int v:g[u])if(v!=p)d(v,u),sz[u]+=sz[v],a[u]+=a[v]+sz[v];}void r(int u,int p){for(int v:g[u])if(v!=p)a[v]=a[u]-sz[v]+g.size()-sz[v],r(v,u);}public:vector<int> sumOfDistancesInTree(int n,vector<vector<int>>&e){g.assign(n,{});sz.assign(n,0);a.assign(n,0);for(auto&x:e)g[x[0]].push_back(x[1]),g[x[1]].push_back(x[0]);d(0,-1);r(0,-1);return a;}};
