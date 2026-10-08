#include <vector>
using namespace std;
class Solution {
public:
    int minKBitFlips(vector<int>& a, int k) {
        int n = a.size(), r = 0, cur = 0;
        vector<int> d(n + 1);
        for (int i = 0; i < n; i++) {
            cur ^= d[i];
            if ((a[i] ^ cur) == 0) {
                if (i + k > n) return -1;
                r++;
                cur ^= 1;
                d[i + k] ^= 1;
            }
        }
        return r;
    }
};
