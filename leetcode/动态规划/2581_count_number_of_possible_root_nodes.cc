#include <vector>
#include <set>
using namespace std;
class Solution {vector<vector<int> >g;set<pair<int,int> >s;int k,r;int f(int u,int p){int z=0;for(int v:g[u])if(v!=p)z+=f(v,u)+s.count(make_pair(u,v));return z;}void h(int u,int p,int z){if(z>=k)++r;for(int v:g[u])if(v!=p)h(v,u,z-s.count(make_pair(u,v))+s.count(make_pair(v,u)));}public:int rootCount(vector<vector<int>>&e,vector<vector<int>>&q,int K){k=K;r=0;g.assign(e.size()+1,{});for(auto&x:e)g[x[0]].push_back(x[1]),g[x[1]].push_back(x[0]);for(auto&x:q)s.insert(make_pair(x[0],x[1]));h(0,-1,f(0,-1));return r;}};
