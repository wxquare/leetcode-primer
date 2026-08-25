class Solution {
public:
    int lengthOfLIS1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int ans = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1,dp[i]);
                    ans = max(dp[i],ans);
                }
            }
        }
        return ans;
    }

    int lengthOfLIS(vector<int>& nums){
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            if(t.size() == 0 || nums[i] > t.back()){
                t.push_back(nums[i]);
            }else{
                int p = lower_bound(t.begin(),t.end(),nums[i]) - t.begin();
                t[p] = nums[i];
            }
        }
        return t.size();
    }

};