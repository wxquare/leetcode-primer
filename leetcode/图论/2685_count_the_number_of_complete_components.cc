#include <vector>
using namespace std;
class Solution { public:int countCompleteComponents(int n,vector<vector<int>>&edges){vector<vector<int>>g(n);for(const auto&e:edges){g[e[0]].push_back(e[1]);g[e[1]].push_back(e[0]);}vector<int>seen(n);int ans=0;for(int s=0;s<n;++s)if(!seen[s]){long long vertices=0,degrees=0;vector<int>st(1,s);seen[s]=1;for(int p=0;p<(int)st.size();++p){int u=st[p];++vertices;degrees+=g[u].size();for(int v:g[u])if(!seen[v])seen[v]=1,st.push_back(v);}ans+=degrees==vertices*(vertices-1);}return ans;} };
