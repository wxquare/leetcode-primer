#include <array>
#include <vector>
using namespace std;
class Solution {
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        array<int, 21> total{};
        for (int x : group) ++total[x];
        vector<int> parent(n, -1), order(1, 0);
        parent[0] = 0;
        for (int p = 0; p < (int)order.size(); ++p) {
            int u = order[p];
            for (int v : g[u])
                if (parent[v] < 0) parent[v] = u, order.push_back(v);
        }
        vector<array<int, 21>> cnt(n);
        long long ans = 0;
        for (int p = n - 1; p >= 0; --p) {
            int u = order[p];
            ++cnt[u][group[u]];
            if (u) {
                for (int label = 1; label <= 20; ++label) {
                    long long inside = cnt[u][label];
                    ans += inside * (total[label] - inside);
                    cnt[parent[u]][label] += cnt[u][label];
                }
            }
        }
        return ans;
    }
};
