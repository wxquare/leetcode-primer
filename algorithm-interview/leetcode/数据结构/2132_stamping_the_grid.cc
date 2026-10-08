#include <vector>
using namespace std;
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& g, int h, int w) {
        int m = g.size(), n = g[0].size();
        vector<vector<int>> p(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                p[i + 1][j + 1] = g[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j];
        vector<vector<int>> d(m + 1, vector<int>(n + 1));
        for (int i = 0; i + h <= m; i++)
            for (int j = 0; j + w <= n; j++)
                if (p[i + h][j + w] - p[i][j + w] - p[i + h][j] + p[i][j] == 0)
                    d[i][j]++, d[i + h][j]--, d[i][j + w]++, d[i + h][j + w]--;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (i) d[i][j] += d[i - 1][j];
                if (j) d[i][j] += d[i][j - 1];
                if (i && j) d[i][j] -= d[i - 1][j - 1];
                if (!g[i][j] && !d[i][j]) return false;
            }
        return true;
    }
};
