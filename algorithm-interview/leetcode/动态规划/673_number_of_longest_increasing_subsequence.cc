#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n = a.size(), ans = 0, best = 0;
        vector<int> l(n, 1), c(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (a[j] < a[i]) {
                    if (l[j] + 1 > l[i]) l[i] = l[j] + 1, c[i] = c[j];
                    else if (l[j] + 1 == l[i]) c[i] += c[j];
                }
            if (l[i] > best) best = l[i], ans = c[i];
            else if (l[i] == best) ans += c[i];
        }
        return ans;
    }
};
