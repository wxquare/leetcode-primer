#include <vector>
using namespace std;
class Solution {
    void go(vector<vector<int>>& h, vector<vector<int>>& v, int i, int j) {
        if (v[i][j]) return;
        v[i][j] = 1;
        static int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int x = i + di[k], y = j + dj[k];
            if (x >= 0 && x < (int)h.size() && y >= 0 && y < (int)h[0].size() && h[x][y] >= h[i][j])
                go(h, v, x, y);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        if (h.empty()) return {};
        int m = h.size(), n = h[0].size();
        vector<vector<int>> a(m, vector<int>(n)), b = a;
        for (int i = 0; i < m; i++) go(h, a, i, 0), go(h, b, i, n - 1);
        for (int j = 0; j < n; j++) go(h, a, 0, j), go(h, b, m - 1, j);
        vector<vector<int>> r;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] && b[i][j]) r.push_back({i, j});
        return r;
    }
};
