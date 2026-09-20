#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<vector<int>> g;
    vector<int> d, u;
    int w(int x) { return x % 2 ? 1 : 2; }
    int down(int x, int p) {
        int z = 0;
        for (int y : g[x])
            if (y != p) z = max(z, down(y, x) + w(y));
        return d[x] = z;
    }
    void up(int x, int p) {
        int best1 = -1, best2 = -1, id = -1;
        for (int y : g[x])
            if (y != p) {
                int z = d[y] + w(y);
                if (z > best1) best2 = best1, best1 = z, id = y;
                else if (z > best2) best2 = z;
            }
        for (int y : g[x])
            if (y != p) {
                int sib = (y == id ? best2 : best1);
                u[y] = max(u[x] + w(x), sib < 0 ? 0 : sib + w(x));
                up(y, x);
            }
    }

public:
    vector<int> timeTaken(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        g.assign(n, {});
        d.assign(n, 0);
        u.assign(n, 0);
        for (auto& e : edges) g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        down(0, -1);
        up(0, -1);
        vector<int> r(n);
        for (int i = 0; i < n; i++) r[i] = max(d[i], u[i]);
        return r;
    }
};
