#include <string>
using namespace std;
class Solution {
    bool ok(int x, int t) {
        if (x == 0) return t == 0;
        for (int d = 10; d <= x * 10; d *= 10)
            if (ok(x / d, t - x % d)) return true;
        return false;
    }

public:
    int punishmentNumber(int n) {
        int r = 0;
        for (int i = 1; i <= n; ++i)
            if (ok(i * i, i)) r += i * i;
        return r;
    }
};
