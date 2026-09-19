#include <vector>
#include <queue>
using namespace std;
class Solution{public:int shortestPath(vector<vector<int>>&g,int k){int m=g.size(),n=g[0].size();queue<vector<int>>q;q.push({0,0,k});vector<vector<int>>best(m,vector<int>(n,-1));best[0][0]=k;int d=0;while(!q.empty()){int z=q.size();while(z--){auto t=q.front();q.pop();if(t[0]==m-1&&t[1]==n-1)return d;static int di[]={1,-1,0,0},dj[]={0,0,1,-1};for(int x=0;x<4;x++){int i=t[0]+di[x],j=t[1]+dj[x],e=t[2];if(i>=0&&i<m&&j>=0&&j<n&&(e-=g[i][j])>=0&&e>best[i][j])best[i][j]=e,q.push({i,j,e});}}d++;}return -1;}};
