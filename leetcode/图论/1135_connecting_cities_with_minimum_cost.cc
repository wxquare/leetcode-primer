#include <vector>
#include <algorithm>
using namespace std; class Solution{int f(vector<int>&p,int x){return p[x]==x?x:p[x]=f(p,p[x]);}public:int minimumCost(int n,vector<vector<int>>&c){sort(c.begin(),c.end(),[](const vector<int>&a,const vector<int>&b){return a[2]<b[2];});vector<int>p(n+1);for(int i=1;i<=n;i++)p[i]=i;int r=0,k=0;for(auto&e:c){int a=f(p,e[0]),b=f(p,e[1]);if(a!=b)p[a]=b,r+=e[2],k++;}return k==n-1?r:-1;}};
