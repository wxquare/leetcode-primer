#include <algorithm>
using namespace std;
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long separate = 1LL * cost1 * need1 + 1LL * cost2 * need2;
        long long bundles = 1LL * costBoth * max(need1, need2);
        int common = min(need1, need2);
        long long mixed = 1LL * costBoth * common + 1LL * (need1 - common) * cost1 +
                          1LL * (need2 - common) * cost2;
        return min(separate, min(bundles, mixed));
    }
};
