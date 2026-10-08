/*

你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。


输入：[1,2,3,1]
输出：4
解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

*/

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            1. 求最优问题
            2. 线性dp
            2. 
               dp[i][0]， 表示从0到i且i不取的大小
               dp[i][1]， 表示从0到i的且取i的最高金额，
            3. 递推公式
            dp[i][0] = max(dp[i-1][0],dp[i-1][1])
            dp[i][1] = dp[i-1][0]+nums[i])
        */
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = dp[i-1][0]+nums[i];
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};

int main(){
    vector<int> nums = {1,2,3,1};
    std::cout << Solution().rob(nums) << std::endl;
}