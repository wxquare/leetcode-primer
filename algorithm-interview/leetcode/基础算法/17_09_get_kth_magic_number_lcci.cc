#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> a(k);
        a[0] = 1;
        int p3 = 0, p5 = 0, p7 = 0;
        for (int i = 1; i < k; ++i) {
            a[i] = min({a[p3] * 3, a[p5] * 5, a[p7] * 7});
            if (a[i] == a[p3] * 3) ++p3;
            if (a[i] == a[p5] * 5) ++p5;
            if (a[i] == a[p7] * 7) ++p7;
        }
        return a[k - 1];
    }
};
