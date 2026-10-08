#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxGap(string skill, string station) {
        int n = skill.size(), m = station.size();
        vector<int> first(n, -1), last(n, -1);
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < m && station[j] != skill[i]) ++j;
            if (j == m) return 0;
            first[i] = j++;
        }
        for (int i = n - 1, j = m - 1; i >= 0; --i) {
            while (j >= 0 && station[j] != skill[i]) --j;
            last[i] = j--;
        }
        int ans = 0;
        for (int i = 1; i < n; ++i) ans = max(ans, last[i] - first[i - 1]);
        return ans;
    }
};
