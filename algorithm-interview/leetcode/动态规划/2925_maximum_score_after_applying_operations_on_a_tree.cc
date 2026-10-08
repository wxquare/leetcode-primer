#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
    vector<vector<int>> g;
    vector<int> v;
    long long dfs(int u, int p) {
        long long child = 0;
        bool leaf = true;
        for (int x : g[u])
            if (x != p) {
                leaf = false;
                child += dfs(x, u);
            }
        return leaf ? v[u] : min((long long)v[u], child);
    }

public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        v = values;
        g.assign(v.size(), vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long total = accumulate(v.begin(), v.end(), 0LL);
        return total - dfs(0, -1);
    }
};
