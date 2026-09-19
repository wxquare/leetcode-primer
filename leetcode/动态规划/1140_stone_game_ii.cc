#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int stoneGameII(vector<int>&a){int n=a.size();vector<int>s(n+1);for(int i=n-1;i>=0;i--)s[i]=s[i+1]+a[i];vector<vector<int>>d(n,vector<int>(n+1));for(int i=n-1;i>=0;i--)for(int m=n;m>=1;m--){if(i+2*m>=n)d[i][m]=s[i];else for(int x=1;x<=2*m;x++)d[i][m]=max(d[i][m],s[i]-d[i+x][max(m,x)]);}return d[0][1];} };
