#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& a) {
        int n = a[0].size(), r = 0;
        vector<int> d(n + 1);
        for (auto& x : a)
            for (int j = 1, p = 0; j <= n; j++) {
                int q = d[j];
                d[j] = x[j - 1] ? min({d[j], d[j - 1], p}) + 1 : 0;
                r += d[j];
                p = q;
            }
        return r;
    }
};
