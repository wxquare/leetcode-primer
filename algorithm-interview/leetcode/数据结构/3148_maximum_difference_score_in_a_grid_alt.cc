#include <vector>
#include <algorithm>
using namespace std;
class GridScoreSolution {
public:
    int maxScore(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), r = -1e9;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                for (int x = i + 1; x < m; x++) r = max(r, g[x][j] - g[i][j]);
                for (int x = j + 1; x < n; x++) r = max(r, g[i][x] - g[i][j]);
            }
        return r;
    }
};
