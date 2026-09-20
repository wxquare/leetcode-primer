#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), fresh = 0, t = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (g[i][j] == 1) fresh++;
                else if (g[i][j] == 2) q.push({i, j});
            }
        while (!q.empty()) {
            int z = q.size();
            while (z--) {
                auto p = q.front();
                q.pop();
                static int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
                for (int k = 0; k < 4; k++) {
                    int i = p.first + di[k], j = p.second + dj[k];
                    if (i >= 0 && i < m && j >= 0 && j < n && g[i][j] == 1)
                        g[i][j] = 2, fresh--, q.push({i, j});
                }
            }
            if (!q.empty()) t++;
        }
        return fresh ? -1 : t;
    }
};
