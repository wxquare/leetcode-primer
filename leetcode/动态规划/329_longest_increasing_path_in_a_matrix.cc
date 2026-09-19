#include <vector>
#include <algorithm>
using namespace std;
class Solution{int dfs(vector<vector<int>>&a,vector<vector<int>>&d,int i,int j){if(d[i][j])return d[i][j];int r=1;static int di[]={1,-1,0,0},dj[]={0,0,1,-1};for(int k=0;k<4;k++){int x=i+di[k],y=j+dj[k];if(x>=0&&x<(int)a.size()&&y>=0&&y<(int)a[0].size()&&a[x][y]>a[i][j])r=max(r,1+dfs(a,d,x,y));}return d[i][j]=r;}public:int longestIncreasingPath(vector<vector<int>>&a){if(a.empty())return 0;vector<vector<int>>d(a.size(),vector<int>(a[0].size()));int r=0;for(int i=0;i<(int)a.size();i++)for(int j=0;j<(int)a[0].size();j++)r=max(r,dfs(a,d,i,j));return r;}};
