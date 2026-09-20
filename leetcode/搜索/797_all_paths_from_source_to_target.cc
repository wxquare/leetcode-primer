#include <vector>
using namespace std;
class Solution {
    void go(vector<vector<int>>& g, int u, vector<int>& p, vector<vector<int>>& r) {
        if (u == (int)g.size() - 1) {
            r.push_back(p);
            return;
        }
        for (int v : g[u]) p.push_back(v), go(g, v, p, r), p.pop_back();
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        vector<vector<int>> r;
        vector<int> p(1, 0);
        go(g, 0, p, r);
        return r;
    }
};
