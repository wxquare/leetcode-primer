#include <vector>
using namespace std;
class Solution { public:vector<int> mostCompetitive(vector<int>&nums,int k){vector<int>s;for(int i=0;i<nums.size();++i){while(!s.empty()&&s.back()>nums[i]&&s.size()-1+nums.size()-i>=k)s.pop_back();if(s.size()<k)s.push_back(nums[i]);}return s;} };
