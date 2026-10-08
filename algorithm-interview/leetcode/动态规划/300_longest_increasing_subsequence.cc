/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。


输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
*/


#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};


class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int size = nums.size();
		if (size < 2)  return size;

        vector<int> dp;
        dp.push_back(nums[0]);
		int res = 0;
		for (int i = 1; i < size; i++) {
            if(nums[i] > dp.back()){
                dp.push_back(nums[i]);
            }else{
                auto pos = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
                dp[pos] = nums[i];
            }
		}
		return dp.size();
	}
};

