#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
class Solution {
    vector<vector<pair<int, int>>> g;
    vector<int> value, seen;
    int limit, ans;
    void dfs(int u, int elapsed, int score) {
        if (u == 0) ans = max(ans, score);
        for (const auto& e : g[u])
            if (elapsed + e.second <= limit) {
                int v = e.first;
                bool first = !seen[v];
                ++seen[v];
                dfs(v, elapsed + e.second, score + (first ? value[v] : 0));
                --seen[v];
            }
    }

public:
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        value = values;
        limit = maxTime;
        g.assign(values.size(), {});
        for (const auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        seen.assign(values.size(), 0);
        seen[0] = 1;
        ans = values[0];
        dfs(0, 0, values[0]);
        return ans;
    }
};
