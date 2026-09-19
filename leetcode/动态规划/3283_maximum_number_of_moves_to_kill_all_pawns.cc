#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
class Solution {int dist[16][16];int memo[16][1<<15][2];vector<vector<int> >p;int n;int go(int at,int mask,int turn){if(!mask)return 0;int &r=memo[at][mask][turn];if(r!=-1)return r;r=turn?0:1000000;for(int i=0;i<n;i++)if(mask>>i&1){int z=dist[at][i]+go(i,mask^(1<<i),turn^1);r=turn?max(r,z):min(r,z);}return r;}public:int maxMoves(int kx,int ky,vector<vector<int>>&positions){p=positions;n=p.size();vector<vector<int> >q=p;q.push_back(vector<int>{kx,ky});for(int s=0;s<=n;s++){int d[50][50];for(int i=0;i<50;i++)for(int j=0;j<50;j++)d[i][j]=-1;queue<pair<int,int> >b;b.push(make_pair(q[s][0],q[s][1]));d[q[s][0]][q[s][1]]=0;int dx[8]={1,1,2,2,-1,-1,-2,-2},dy[8]={2,-2,1,-1,2,-2,1,-1};while(!b.empty()){pair<int,int>x=b.front();b.pop();for(int z=0;z<8;z++){int a=x.first+dx[z],c=x.second+dy[z];if(a>=0&&a<50&&c>=0&&c<50&&d[a][c]<0)d[a][c]=d[x.first][x.second]+1,b.push(make_pair(a,c));}}for(int i=0;i<n;i++)dist[s][i]=d[p[i][0]][p[i][1]];}memset(memo,-1,sizeof(memo));return go(n,(1<<n)-1,1);}};
