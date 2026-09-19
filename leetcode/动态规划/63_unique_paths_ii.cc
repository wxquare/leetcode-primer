#include <vector>
using namespace std;
class Solution{public:int uniquePathsWithObstacles(vector<vector<int>>&g){if(g.empty())return 0;vector<int>d(g[0].size());d[0]=1;for(auto&r:g)for(int j=0;j<(int)r.size();j++)d[j]=r[j]?0:(j?d[j]+d[j-1]:d[j]);return d.back();}};
