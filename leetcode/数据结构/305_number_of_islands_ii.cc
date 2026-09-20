#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& p) {
        vector<int> par(m * n, -1), r;
        int c = 0;
        function<int(int)> f = [&](int x) { return par[x] == x ? x : par[x] = f(par[x]); };
        for (auto& x : p) {
            int z = x[0] * n + x[1];
            if (par[z] >= 0) {
                r.push_back(c);
                continue;
            }
            par[z] = z;
            c++;
            for (int d = 0; d < 4; d++) {
                int i = x[0] + (d == 0) - (d == 1), j = x[1] + (d == 2) - (d == 3);
                if (i >= 0 && i < m && j >= 0 && j < n && par[i * n + j] >= 0) {
                    int a = f(z), b = f(i * n + j);
                    if (a != b) par[a] = b, c--;
                }
            }
            r.push_back(c);
        }
        return r;
    }
};
