#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
    unordered_map<int, bool> m;
    int n, t;
    bool go(int mask, int sum) {
        if (m.count(mask)) return m[mask];
        for (int i = 1; i <= n; i++)
            if (!(mask >> (i - 1) & 1) && (sum + i >= t || !go(mask | 1 << (i - 1), sum + i)))
                return m[mask] = true;
        return m[mask] = false;
    }

public:
    bool canIWin(int a, int b) {
        n = a;
        t = b;
        if (t <= 0) return true;
        if (n * (n + 1) / 2 < t) return false;
        return go(0, 0);
    }
};
