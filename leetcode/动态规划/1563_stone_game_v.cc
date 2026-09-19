#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int stoneGameV(vector<int>&a){int n=a.size();vector<int>s(n+1);for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];vector<vector<int>>d(n,vector<int>(n));for(int z=1;z<n;z++)for(int l=0;l+z<n;l++){int r=l+z;for(int m=l;m<r;m++){int x=s[m+1]-s[l],y=s[r+1]-s[m+1];if(x<y)d[l][r]=max(d[l][r],x+d[l][m]);else if(x>y)d[l][r]=max(d[l][r],y+d[m+1][r]);else d[l][r]=max(d[l][r],x+max(d[l][m],d[m+1][r]));}}return d[0][n-1];}};
