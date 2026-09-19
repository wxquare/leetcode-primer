#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int maxScore(vector<vector<int>>&g){int m=g.size(),n=g[0].size(),r=-1e9;vector<vector<int>>d(m,vector<int>(n,1e9));for(int i=m-1;i>=0;i--)for(int j=n-1;j>=0;j--){if(i+1<m)r=max(r,d[i+1][j]-g[i][j]),d[i][j]=min(d[i][j],d[i+1][j]);if(j+1<n)r=max(r,d[i][j+1]-g[i][j]),d[i][j]=min(d[i][j],d[i][j+1]);d[i][j]=min(d[i][j],g[i][j]);}return r;}};
