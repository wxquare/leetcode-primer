#include <vector>
using namespace std;
class Solution{public:int uniquePaths(int m,int n){vector<int>d(n,1);for(int i=1;i<m;i++)for(int j=1;j<n;j++)d[j]+=d[j-1];return d[n-1];}};
