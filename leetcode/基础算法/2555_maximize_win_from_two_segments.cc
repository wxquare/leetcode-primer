#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int maximizeWin(vector<int>& prizePositions,int k){int n=prizePositions.size(),l=0,best=0,ans=0;vector<int> dp(n+1);for(int r=0;r<n;++r){while(prizePositions[r]-prizePositions[l]>k)++l;int len=r-l+1;ans=max(ans,len+dp[l]);dp[r+1]=max(dp[r],len);}return ans;} };
