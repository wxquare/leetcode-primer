#include <vector>
using namespace std;

class Solution {
public:
    int stringCount(int n) {
        const long long mod = 1000000007;
        vector<vector<long long> > dp(2, vector<long long>(12, 0));
        dp[0][0] = 1;

        for (int length = 0; length < n; ++length) {
            int current = length & 1;
            int next = current ^ 1;
            for (int state = 0; state < 12; ++state) dp[next][state] = 0;

            for (int state = 0; state < 12; ++state) {
                long long ways = dp[current][state];
                if (ways == 0) continue;
                int l = state / 6;
                int e = state / 2 % 3;
                int t = state % 2;

                dp[next][state] = (dp[next][state] + ways * 23) % mod;
                int withL = 6 + e * 2 + t;
                int withE = l * 6 + (e < 2 ? e + 1 : 2) * 2 + t;
                int withT = l * 6 + e * 2 + 1;
                dp[next][withL] = (dp[next][withL] + ways) % mod;
                dp[next][withE] = (dp[next][withE] + ways) % mod;
                dp[next][withT] = (dp[next][withT] + ways) % mod;
            }
        }
        return static_cast<int>(dp[n & 1][11]);
    }
};
