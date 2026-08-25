#include <vector>
using namespace std;

class Solution1{
public:
    int minimumOperations(vector<int>& nums){
        /*
            1. 最少 -> (贪心、dp或者搜索)
        */
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(4,INT_MAX));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;
        for(int i=0;i<n;i++){
            dp[i+1][1] = dp[i][1] + (nums[i] != 1);
            dp[i+1][2] = min(dp[i][1],dp[i][2]) + (nums[i] != 2);
            dp[i+1][3] = min(min(dp[i][1],dp[i][2]),dp[i][3]) + (nums[i] != 3);
        }
        return min(min(dp[n][1],dp[n][2]),dp[n][3]);
    }
};

class Solution{
public:
    int minimumOperations(vector<int>& nums){
        /*
            1. 最少 -> (贪心、dp或者搜索)
        */
        int n = nums.size();
        vector<int> dp(4,0);
        for(int i=0;i<n;i++){
            dp[3] = min(min(dp[1],dp[2]),dp[3]) + (nums[i] != 3);
            dp[2] = min(dp[1],dp[2]) + (nums[i] != 2);
            dp[1] = dp[1] + (nums[i] != 1);
        }
        return min(min(dp[1],dp[2]),dp[3]);
    }
};


