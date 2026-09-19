#include <vector>
using namespace std;
class Solution { public:int waysToReachTarget(int target,vector<vector<int>>&types){const int M=1000000007;vector<int>d(target+1);d[0]=1;for(auto&t:types)for(int s=target;s>=0;s--){long long v=0;for(int k=1;k<=t[0]&&k*t[1]<=s;k++)v+=d[s-k*t[1]];d[s]=(d[s]+v)%M;}return d[target];} };
