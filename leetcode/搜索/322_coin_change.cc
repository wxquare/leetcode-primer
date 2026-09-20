#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int s = 1; s <= amount; ++s)
            for (int c : coins)
                if (c <= s) dp[s] = min(dp[s], dp[s - c] + 1);
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
