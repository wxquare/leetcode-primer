#include <vector>
using namespace std;
class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int M = 1000000007;
        vector<int> d(target + 1);
        d[0] = 1;
        for (int z = 0; z < n; z++) {
            vector<int> q(target + 1);
            for (int s = 0; s <= target; s++)
                for (int x = 1; x <= k && x <= s; x++) q[s] = (q[s] + d[s - x]) % M;
            d.swap(q);
        }
        return d[target];
    }
};
