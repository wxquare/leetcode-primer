#include <functional>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<vector<pair<int, int>>> g(n);
        for (const auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }
        const long long INF = 1LL << 60;
        vector<long long> d(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;
        d[0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            pair<long long, int> cur = q.top();
            q.pop();
            if (cur.first != d[cur.second]) continue;
            for (const auto& e : g[cur.second]) {
                long long nd = cur.first + e.second;
                if (nd < d[e.first] && nd < disappear[e.first]) {
                    d[e.first] = nd;
                    q.push({nd, e.first});
                }
            }
        }
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i)
            if (d[i] != INF) ans[i] = d[i];
        return ans;
    }
};
