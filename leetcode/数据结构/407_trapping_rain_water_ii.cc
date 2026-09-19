#include <vector>
#include <queue>
#include <algorithm>
using namespace std; class Solution{public:int trapRainWater(vector<vector<int>>&a){if(a.empty())return 0;int m=a.size(),n=a[0].size(),r=0;using P=pair<int,pair<int,int>>;priority_queue<P,vector<P>,greater<P>>q;vector<vector<char>>v(m,vector<char>(n));for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(i==0||j==0||i==m-1||j==n-1)q.push({a[i][j],{i,j}}),v[i][j]=1;while(!q.empty()){auto z=q.top();q.pop();for(int d=0;d<4;d++){int i=z.second.first+(d==0)-(d==1),j=z.second.second+(d==2)-(d==3);if(i>=0&&i<m&&j>=0&&j<n&&!v[i][j])v[i][j]=1,r+=max(0,z.first-a[i][j]),q.push({max(z.first,a[i][j]),{i,j}});}}return r;}};
