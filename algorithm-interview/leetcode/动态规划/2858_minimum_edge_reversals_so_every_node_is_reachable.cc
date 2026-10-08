#include <vector>
using namespace std;
class Solution {
    vector<vector<pair<int, int>>> g;
    vector<int> r;
    int f(int u, int p) {
        int z = 0;
        for (auto e : g[u])
            if (e.first != p) z += f(e.first, u) + e.second;
        return z;
    }
    void h(int u, int p) {
        for (auto e : g[u])
            if (e.first != p) {
                r[e.first] = r[u] + (e.second ? -1 : 1);
                h(e.first, u);
            }
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& e) {
        g.assign(n, vector<pair<int, int>>());
        r.assign(n, 0);
        for (auto& x : e) {
            g[x[0]].push_back(make_pair(x[1], 0));
            g[x[1]].push_back(make_pair(x[0], 1));
        }
        r[0] = f(0, -1);
        h(0, -1);
        return r;
    }
};
