#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Graph { vector<vector<pair<int,int>>>g;public:Graph(int n,vector<vector<int>>&edges):g(n){for(const auto&e:edges)addEdge(e);}void addEdge(vector<int>e){g[e[0]].push_back({e[1],e[2]});}int shortestPath(int node1,int node2){const long long INF=1LL<<60;vector<long long>d(g.size(),INF);priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;d[node1]=0;q.push({0,node1});while(!q.empty()){pair<long long,int>cur=q.top();q.pop();if(cur.first!=d[cur.second])continue;if(cur.second==node2)return cur.first;for(const auto&e:g[cur.second])if(d[e.first]>cur.first+e.second){d[e.first]=cur.first+e.second;q.push({d[e.first],e.first});}}return -1;} };
