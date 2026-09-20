#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumDetonation(vector<vector<int>>& b) {
        int n = b.size(), ans = 0;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i != j) {
                    long long dx = b[i][0] - b[j][0], dy = b[i][1] - b[j][1], r = b[i][2];
                    if (dx * dx + dy * dy <= r * r) g[i].push_back(j);
                }
        for (int s = 0; s < n; ++s) {
            vector<int> seen(n), st(1, s);
            seen[s] = 1;
            for (int p = 0; p < (int)st.size(); ++p)
                for (int v : g[st[p]])
                    if (!seen[v]) seen[v] = 1, st.push_back(v);
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
