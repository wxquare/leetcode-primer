#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        const int INF = 1000000000;
        vector<int> dp(sum + 1, INF);
        dp[0] = 0;
        for (int x : nums) {
            vector<pair<int, int>> ways;
            for (long long y = x, c = 0; y <= sum; y *= 2, ++c)
                ways.push_back(make_pair((int)y, (int)c));
            for (int y = x / 2, c = 1; y; y /= 2, ++c) ways.push_back(make_pair(y, c));
            for (int s = sum; s >= 0; --s)
                for (auto& w : ways)
                    if (w.first <= s) dp[s] = min(dp[s], dp[s - w.first] + w.second);
        }
        return dp[sum] == INF ? -1 : dp[sum];
    }
};
