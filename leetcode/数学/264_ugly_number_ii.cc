#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> a(n);
        a[0] = 1;
        int i = 0, j = 0, k = 0;
        for (int x = 1; x < n; ++x) {
            a[x] = min(a[i] * 2, min(a[j] * 3, a[k] * 5));
            while (a[i] * 2 == a[x]) ++i;
            while (a[j] * 3 == a[x]) ++j;
            while (a[k] * 5 == a[x]) ++k;
        }
        return a[n - 1];
    }
};
