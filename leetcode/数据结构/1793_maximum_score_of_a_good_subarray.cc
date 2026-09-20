#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        int l = k, r = k, m = a[k], ans = m;
        while (l || r) {
            if (l == 0 || r < a.size() - 1 && a[r + 1] > a[l - 1]) m = min(m, a[++r]);
            else m = min(m, a[--l]);
            ans = max(ans, m * (r - l + 1));
        }
        return ans;
    }
};
