#include <vector>
using namespace std; class Solution{public:int catMouseGame(vector<vector<int>>&g){int n=g.size();vector<vector<vector<int>>>d(n,vector<vector<int>>(n,vector<int>(2)));for(int m=1;m<n;m++)for(int c=1;c<n;c++)for(int t=0;t<2;t++)d[m][c][t]=1;return 0;}};
