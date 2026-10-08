#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    int f(vector<int>& p, int x) { return p[x] == x ? x : p[x] = f(p, p[x]); }

public:
    int minCostToSupplyWater(int n, vector<int>& w, vector<vector<int>>& p) {
        vector<vector<int>> e;
        for (int i = 0; i < n; i++) e.push_back({0, i + 1, w[i]});
        e.insert(e.end(), p.begin(), p.end());
        sort(e.begin(), e.end(),
             [](const vector<int>& a, const vector<int>& b) { return a[2] < b[2]; });
        vector<int> q(n + 1);
        for (int i = 0; i <= n; i++) q[i] = i;
        int r = 0;
        for (auto& x : e) {
            int a = f(q, x[0]), b = f(q, x[1]);
            if (a != b) q[a] = b, r += x[2];
        }
        return r;
    }
};
