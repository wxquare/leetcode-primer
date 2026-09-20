#include <vector>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        vector<int> c(g.size());
        for (int i = 0; i < g.size(); ++i)
            if (!c[i]) {
                c[i] = 1;
                vector<int> q(1, i);
                for (int h = 0; h < q.size(); ++h)
                    for (int x : g[q[h]]) {
                        if (!c[x]) c[x] = -c[q[h]], q.push_back(x);
                        else if (c[x] == c[q[h]]) return false;
                    }
            }
        return true;
    }
};
