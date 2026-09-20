#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& h) {
        int m = h.size(), n = h[0].size();
        vector<vector<int>> d(m, vector<int>(n, 1000000000));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        d[0][0] = 0;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int e = t[0], i = t[1], j = t[2];
            if (e != d[i][j]) continue;
            if (i == m - 1 && j == n - 1) return e;
            static int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
            for (int k = 0; k < 4; k++) {
                int x = i + di[k], y = j + dj[k];
                if (x >= 0 && x < m && y >= 0 && y < n) {
                    int ne = max(e, abs(h[x][y] - h[i][j]));
                    if (ne < d[x][y]) d[x][y] = ne, q.push({ne, x, y});
                }
            }
        }
        return 0;
    }
};
