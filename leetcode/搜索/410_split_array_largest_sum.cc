#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) { long long l=*max_element(nums.begin(),nums.end()),r=accumulate(nums.begin(),nums.end(),0LL); while(l<r){long long m=(l+r)/2,sum=0; int parts=1; for(int v:nums){if(sum+v>m){++parts;sum=0;} sum+=v;} if(parts>k) l=m+1; else r=m;} return (int)l; }
};
