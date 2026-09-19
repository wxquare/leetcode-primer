#include <vector>
using namespace std;
class Solution{int f(vector<int>&p,int x){return p[x]==x?x:p[x]=f(p,p[x]);}public:bool validPath(int n,vector<vector<int>>&e,int s,int t){vector<int>p(n);for(int i=0;i<n;i++)p[i]=i;for(auto&x:e){int a=f(p,x[0]),b=f(p,x[1]);p[a]=b;}return f(p,s)==f(p,t);}};
