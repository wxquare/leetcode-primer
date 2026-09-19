#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int smallestRangeII(vector<int>& nums,int k){sort(nums.begin(),nums.end());int ans=nums.back()-nums.front();for(int i=0;i+1<nums.size();++i){int hi=max(nums[i]+k,nums.back()-k),lo=min(nums.front()+k,nums[i+1]-k);ans=min(ans,hi-lo);}return ans;} };
