#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> r;
        if (m.empty()) return r;
        int t = 0, b = m.size() - 1, l = 0, rr = m[0].size() - 1;
        while (t <= b && l <= rr) {
            for (int j = l; j <= rr; j++) r.push_back(m[t][j]);
            ++t;
            for (int i = t; i <= b; i++) r.push_back(m[i][rr]);
            --rr;
            if (t <= b)
                for (int j = rr; j >= l; j--) r.push_back(m[b][j]);
            --b;
            if (l <= rr)
                for (int i = b; i >= t; i--) r.push_back(m[i][l]);
            ++l;
        }
        return r;
    }
};
