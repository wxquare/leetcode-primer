#include <vector>
#include <unordered_map>
using namespace std;

class Solution{
public:
    int longestEqualSubarray(vector<int>& nums,int k){
        /*
            1. 最长(贪心、DP、搜索)
            2. 1<=nums[i]<=nums.length
        */
        //分组
        unordered_map<int,vector<int>> groups;
        for(int i=0;i<nums.size();i++){
            groups[nums[i]].push_back(i);
        }
        int ans = 1;
        for(auto & [_,pos] : groups){
            if(pos.size() < 2) continue;
            // 双指针
            int left = 0;
            for(int i=1;i<pos.size();i++){
                while(pos[i] - pos[left] + 1 - (i-left+1) > k){
                    left++;
                }
                ans = max(ans,i-left+1);
            }
        }
        return ans;
    }
};