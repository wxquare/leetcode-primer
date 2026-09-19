#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
class Solution { pair<vector<int>,vector<int>>color(const vector<vector<int>>&edges){int n=edges.size()+1;vector<vector<int>>g(n);for(const auto&e:edges){g[e[0]].push_back(e[1]);g[e[1]].push_back(e[0]);}vector<int>c(n,-1),cnt(2);c[0]=0;vector<int>q(1,0);for(int p=0;p<n;++p){int u=q[p];++cnt[c[u]];for(int v:g[u])if(c[v]<0)c[v]=c[u]^1,q.push_back(v);}return {c,cnt};}public:vector<int>maxTargetNodes(vector<vector<int>>&edges1,vector<vector<int>>&edges2){pair<vector<int>,vector<int>>a=color(edges1),b=color(edges2);int extra=edges2.empty()?0:max(b.second[0],b.second[1]);vector<int>ans(a.first.size());for(int i=0;i<(int)ans.size();++i)ans[i]=a.second[a.first[i]]+extra;return ans;} };
