#include <vector>
using namespace std;
class Solution { public:int combinationSum4(vector<int>&nums,int target){vector<long long>dp(target+1);dp[0]=1;for(int s=1;s<=target;++s)for(int x:nums)if(x<=s)dp[s]+=dp[s-x];return(int)dp[target];} };
