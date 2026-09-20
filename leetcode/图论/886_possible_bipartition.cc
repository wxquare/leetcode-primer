#include <vector>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
        vector<vector<int>> g(n);
        for (auto& e : d) g[e[0] - 1].push_back(e[1] - 1), g[e[1] - 1].push_back(e[0] - 1);
        vector<int> c(n);
        for (int s = 0; s < n; s++)
            if (!c[s]) {
                c[s] = 1;
                vector<int> q(1, s);
                for (int z = 0; z < (int)q.size(); z++)
                    for (int v : g[q[z]])
                        if (!c[v]) c[v] = -c[q[z]], q.push_back(v);
                        else if (c[v] == c[q[z]]) return false;
            }
        return true;
    }
};
