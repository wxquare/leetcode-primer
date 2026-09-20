#include <vector>
using namespace std;
class Solution {
    int f(vector<int>& p, int x) { return p[x] == x ? x : p[x] = f(p, p[x]); }

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& e) {
        int n = e.size();
        vector<int> par(n + 1), cand;
        for (int i = 0; i <= n; i++) par[i] = i;
        vector<int> in(n + 1);
        for (auto& x : e)
            if (in[x[1]]) cand = {in[x[1]], x[1], x[0]};
            else in[x[1]] = x[0];
        vector<int> p = par;
        for (auto& x : e) {
            if (cand.size() && x[0] == cand[0] && x[1] == cand[1]) continue;
            int a = f(p, x[0]), b = f(p, x[1]);
            if (a == b)
                return cand.empty()      ? x
                       : cand[0] == x[0] ? vector<int>{x[0], x[1]}
                                         : vector<int>{cand[0], cand[1]};
            p[a] = b;
        }
        return {cand[0], cand[1]};
    }
};
