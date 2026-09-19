#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int longestOnes(vector<int>& nums,int k){int l=0,z=0,ans=0;for(int r=0;r<nums.size();++r){z+=nums[r]==0;while(z>k)z-=nums[l++]==0;ans=max(ans,r-l+1);}return ans;} };
