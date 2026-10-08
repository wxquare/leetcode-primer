#include <vector>
using namespace std;
class Solution {
public:
    int specialPerm(vector<int>& nums) {
        const int MOD = 1000000007;
        int n = nums.size(), N = 1 << n;
        vector<vector<int>> dp(N, vector<int>(n));
        for (int i = 0; i < n; ++i) dp[1 << i][i] = 1;
        for (int mask = 1; mask < N; ++mask)
            for (int last = 0; last < n; ++last)
                if (dp[mask][last])
                    for (int nxt = 0; nxt < n; ++nxt)
                        if (!(mask >> nxt & 1) &&
                            (nums[last] % nums[nxt] == 0 || nums[nxt] % nums[last] == 0))
                            dp[mask | 1 << nxt][nxt] =
                                (dp[mask | 1 << nxt][nxt] + dp[mask][last]) % MOD;
        int ans = 0;
        for (int x : dp[N - 1]) ans = (ans + x) % MOD;
        return ans;
    }
};
