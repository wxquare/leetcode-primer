#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int getMoneyAmount(int n){vector<vector<int>>d(n+2,vector<int>(n+2));for(int len=2;len<=n;len++)for(int l=1;l+len-1<=n;l++){int r=l+len-1;d[l][r]=1000000000;for(int x=l;x<=r;x++)d[l][r]=min(d[l][r],x+max(d[l][x-1],d[x+1][r]));}return d[1][n];} };
