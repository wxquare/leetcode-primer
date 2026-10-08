#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& e) {
        vector<vector<pair<int, int>>> g(n);
        for (auto& x : e)
            g[x[0] - 1].push_back({x[1] - 1, x[2]}), g[x[1] - 1].push_back({x[0] - 1, x[2]});
        vector<long long> d(n, 1e18);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;
        d[n - 1] = 0;
        q.push({0, n - 1});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            if (t.first != d[t.second]) continue;
            for (auto z : g[t.second])
                if (d[z.first] > t.first + z.second)
                    d[z.first] = t.first + z.second, q.push({d[z.first], z.first});
        }
        vector<int> o(n);
        for (int i = 0; i < n; i++) o[i] = i;
        sort(o.begin(), o.end(), [&](int a, int b) { return d[a] < d[b]; });
        vector<int> w(n);
        w[n - 1] = 1;
        for (int u : o)
            for (auto z : g[u])
                if (d[u] > d[z.first]) w[u] = (w[u] + w[z.first]) % 1000000007;
        return w[0];
    }
};
