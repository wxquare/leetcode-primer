#include <vector>
using namespace std;
class Solution {
    long long dfs(int u,int p,const vector<vector<int> >& g,int seats,long long& ans){long long people=1; for(int v:g[u]) if(v!=p){long long sub=dfs(v,u,g,seats,ans); ans+=(sub+seats-1)/seats; people+=sub;} return people;}
public:
    long long minimumFuelCost(vector<vector<int> >& roads,int seats){vector<vector<int> > g(roads.size()+1); for(const vector<int>& e:roads){g[e[0]].push_back(e[1]);g[e[1]].push_back(e[0]);} long long ans=0; dfs(0,-1,g,seats,ans); return ans;}
};
