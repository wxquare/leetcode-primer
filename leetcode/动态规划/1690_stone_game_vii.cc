#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int stoneGameVII(vector<int>&a){int n=a.size();vector<int>s(n+1),d(n);for(int i=0;i<n;i++)s[i+1]=s[i]+a[i];for(int z=1;z<n;z++)for(int l=0;l+z<n;l++){int r=l+z;d[l]=max(s[r+1]-s[l+1]-d[l+1],s[r]-s[l]-d[l]);}return d[0];}};
