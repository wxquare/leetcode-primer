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
    int maximalSquare(vector<vector<char>>& a) {
        int n = a.empty() ? 0 : a[0].size(), p = 0, b = 0;
        vector<int> d(n + 1);
        for (auto& r : a) {
            p = 0;
            for (int j = 1; j <= n; j++) {
                int q = d[j];
                d[j] = r[j - 1] == '1' ? min({d[j], d[j - 1], p}) + 1 : 0;
                b = max(b, d[j]);
                p = q;
            }
        }
        return b * b;
    }
};
