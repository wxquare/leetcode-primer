#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    long long maxStrength(vector<int>& a) {
        long long hi = a[0], lo = a[0];
        for (int i = 1; i < a.size(); i++) {
            long long x = a[i], p = hi, q = lo;
            hi = max(x, max(p * x, q * x));
            lo = min(x, min(p * x, q * x));
        }
        return hi;
    }
};
