#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> d(n);
        for (int i = n - 1; i >= 0; i--) {
            int p = 0;
            for (int j = i; j < n; j++) {
                int q = d[j];
                d[j] = s[i] == s[j] ? p + 2 : max(d[j], j ? d[j - 1] : 0);
                p = q;
            }
        }
        return d[n - 1];
    }
};
