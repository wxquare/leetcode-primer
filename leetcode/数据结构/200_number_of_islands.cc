#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:int numIslands(vector<vector<char>>&g){int m=g.size(),n=m?g[0].size():0,c=0;function<void(int,int)>f=[&](int i,int j){if(i<0||j<0||i>=m||j>=n||g[i][j]!='1')return;g[i][j]='0';f(i+1,j);f(i-1,j);f(i,j+1);f(i,j-1);};for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(g[i][j]=='1')c++,f(i,j);return c;}};
