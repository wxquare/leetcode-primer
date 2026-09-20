#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& g) {
        int n = g.size(), all = (1 << n) - 1;
        queue<pair<int, int>> q;
        vector<vector<int>> v(1 << n, vector<int>(n));
        for (int i = 0; i < n; i++) q.push({1 << i, i}), v[1 << i][i] = 1;
        int d = 0;
        while (!q.empty()) {
            int z = q.size();
            while (z--) {
                auto t = q.front();
                q.pop();
                int m = t.first, u = t.second;
                if (m == all) return d;
                for (int w : g[u])
                    if (!v[m | 1 << w][w]) v[m | 1 << w][w] = 1, q.push({m | 1 << w, w});
            }
            d++;
        }
        return 0;
    }
};
