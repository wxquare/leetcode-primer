#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumSubstringsInPartition(string s) {
        int n = s.size();
        vector<int> d(n + 1, 1e9);
        d[0] = 0;
        for (int i = 1; i <= n; i++) {
            int c[26] = {}, mx = 0, dist = 0;
            for (int j = i; j >= 1; j--) {
                if (!c[s[j - 1] - 'a']++) dist++;
                mx = max(mx, ++c[s[j - 1] - 'a']);
                if (mx * j == i - j + 1 + mx * (dist - 1)) d[i] = min(d[i], d[j - 1] + 1);
            }
        }
        return d[n];
    }
};
