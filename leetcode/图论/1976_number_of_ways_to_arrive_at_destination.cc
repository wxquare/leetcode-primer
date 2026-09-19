#include <vector>
#include <queue>
#include <climits>
using namespace std;
class Solution{public:int countPaths(int n,vector<vector<int>>&e){vector<vector<pair<int,int>>>g(n);for(auto&x:e)g[x[0]].push_back({x[1],x[2]}),g[x[1]].push_back({x[0],x[2]});vector<long long>d(n,LLONG_MAX),w(n);priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;d[0]=0;w[0]=1;q.push({0,0});while(!q.empty()){auto t=q.top();q.pop();if(t.first!=d[t.second])continue;for(auto z:g[t.second]){long long nd=t.first+z.second;if(nd<d[z.first])d[z.first]=nd,w[z.first]=w[t.second],q.push({nd,z.first});else if(nd==d[z.first])w[z.first]=(w[z.first]+w[t.second])%1000000007;}}return w[n-1];}};
