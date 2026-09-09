class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            dp[i][0] // 到i，且不选的最高金额
            dp[i][1] // 到i，且选择i的最高的金额
        */
        int n = nums.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,0));
        int x = 0, y = 0;
        for(int i=0;i<n;i++){
            int t = x;
            x = max(x,y);
            y = t + nums[i];
        }
        return max(x,y);
    }
};