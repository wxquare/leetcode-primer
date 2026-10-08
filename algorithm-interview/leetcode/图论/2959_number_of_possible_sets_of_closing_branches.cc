#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfSets(int n, int maxDistance, vector<vector<int>>& roads) {
        const int INF = 1000000000, all = 1 << n;
        int ans = 0;
        for (int mask = 0; mask < all; ++mask) {
            vector<vector<int>> d(n, vector<int>(n, INF));
            for (int i = 0; i < n; ++i)
                if (mask >> i & 1) d[i][i] = 0;
            for (const auto& e : roads)
                if ((mask >> e[0] & 1) && (mask >> e[1] & 1))
                    d[e[0]][e[1]] = d[e[1]][e[0]] = min(d[e[0]][e[1]], e[2]);
            for (int k = 0; k < n; ++k)
                if (mask >> k & 1)
                    for (int i = 0; i < n; ++i)
                        if (mask >> i & 1)
                            for (int j = 0; j < n; ++j)
                                if (mask >> j & 1) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            bool ok = true;
            for (int i = 0; i < n; ++i)
                if (mask >> i & 1)
                    for (int j = i + 1; j < n; ++j)
                        if ((mask >> j & 1) && d[i][j] > maxDistance) ok = false;
            ans += ok;
        }
        return ans;
    }
};
