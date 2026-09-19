#include <vector>
#include <algorithm>
using namespace std; class Solution{public:long long maxBalancedSubsequenceSum(vector<int>&a){long long r=a[0],s=0;for(int x:a)s=max((long long)x,s+x),r=max(r,s);return r;}};
