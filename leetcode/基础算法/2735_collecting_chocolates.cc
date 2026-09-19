#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:long long minCost(vector<int>& nums,int x){int n=nums.size();vector<int> best=nums;long long ans=0;for(int r=0;r<n;++r){for(int i=0;i<n;++i)best[i]=min(best[i],nums[(i+r)%n]);long long cur=1LL*r*x;for(int v:best)cur+=v;ans=r==0?cur:min(ans,cur);}return ans;} };
