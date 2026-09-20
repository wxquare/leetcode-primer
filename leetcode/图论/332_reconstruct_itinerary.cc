#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> g;
    vector<string> route;
    void dfs(const string& u) {
        while (!g[u].empty()) {
            string v = g[u].top();
            g[u].pop();
            dfs(v);
        }
        route.push_back(u);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        g.clear();
        route.clear();
        for (const auto& t : tickets) g[t[0]].push(t[1]);
        dfs("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
};
