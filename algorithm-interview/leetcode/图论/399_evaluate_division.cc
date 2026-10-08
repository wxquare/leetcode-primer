#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < (int)equations.size(); ++i) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }
        vector<double> ans;
        for (const auto& q : queries) {
            if (!g.count(q[0]) || !g.count(q[1])) {
                ans.push_back(-1.0);
                continue;
            }
            queue<pair<string, double>> bfs;
            bfs.push({q[0], 1.0});
            unordered_set<string> seen;
            seen.insert(q[0]);
            double found = -1.0;
            while (!bfs.empty()) {
                pair<string, double> cur = bfs.front();
                bfs.pop();
                if (cur.first == q[1]) {
                    found = cur.second;
                    break;
                }
                for (const auto& e : g[cur.first])
                    if (seen.insert(e.first).second) bfs.push({e.first, cur.second * e.second});
            }
            ans.push_back(found);
        }
        return ans;
    }
};
