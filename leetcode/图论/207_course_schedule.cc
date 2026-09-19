#include <queue>
#include <vector>
using namespace std;
class Solution { public:bool canFinish(int n,vector<vector<int>>& p){vector<vector<int>>g(n);vector<int>d(n);for(auto&x:p){g[x[1]].push_back(x[0]);++d[x[0]];}queue<int>q;for(int i=0;i<n;++i)if(!d[i])q.push(i);int c=0;while(!q.empty()){int u=q.front();q.pop();++c;for(int v:g[u])if(!--d[v])q.push(v);}return c==n;} };
