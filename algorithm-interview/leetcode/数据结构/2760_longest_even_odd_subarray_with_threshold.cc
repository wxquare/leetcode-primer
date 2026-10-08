#include <vector>
using namespace std;
class Solution {
public:
    int longestAlternatingSubarray(vector<int>& a, int t) {
        int r = 0, s = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] <= t && (s == 0 ? a[i] % 2 == 0 : a[i - 1] % 2 != a[i] % 2)) s++;
            else s = a[i] <= t && a[i] % 2 == 0;
            r = max(r, s);
        }
        return r;
    }
};
