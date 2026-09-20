#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
    pair<int, int> calc(vector<vector<int>>& e) {
        vector<vector<int>> g(e.size() + 1);
        for (auto& x : e) {
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        function<pair<int, int>(int, int)> dfs = [&](int u, int p) {
            int a = 0, b = 0;
            for (int v : g[u])
                if (v != p) {
                    int z = dfs(v, u).first + 1;
                    if (z > a) b = a, a = z;
                    else if (z > b) b = z;
                }
            return make_pair(a, max(a, b));
        };
        return dfs(0, -1);
    }

public:
    int minimumDiameterAfterMerge(vector<vector<int>>& a, vector<vector<int>>& b) {
        int x = calc(a).second, y = calc(b).second;
        return max(max(x, y), (x + 1) / 2 + (y + 1) / 2 + 1);
    }
};
