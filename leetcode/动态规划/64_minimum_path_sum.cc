#include <vector>
#include <algorithm>
using namespace std;
class Solution{public:int minPathSum(vector<vector<int>>&g){for(int i=0;i<(int)g.size();i++)for(int j=0;j<(int)g[i].size();j++)if(i||j)g[i][j]+=min(i?g[i-1][j]:1000000000,j?g[i][j-1]:1000000000);return g.back().back();}};
