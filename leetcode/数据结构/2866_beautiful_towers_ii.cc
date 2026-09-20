#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& a) {
        int n = a.size();
        long long r = 0;
        for (int p = 0; p < n; p++) {
            long long s = a[p];
            int z = a[p];
            for (int i = p - 1; i >= 0; i--) z = min(z, a[i]), s += z;
            z = a[p];
            for (int i = p + 1; i < n; i++) z = min(z, a[i]), s += z;
            r = max(r, s);
        }
        return r;
    }
};
