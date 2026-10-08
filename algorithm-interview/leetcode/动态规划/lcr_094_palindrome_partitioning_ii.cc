#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = static_cast<int>(s.size());
        if (n == 0) return 0;

        vector<vector<bool> > palindrome(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                palindrome[i][j] = s[i] == s[j] &&
                    (j - i < 2 || palindrome[i + 1][j - 1]);
            }
        }

        vector<int> cuts(n);
        for (int end = 0; end < n; ++end) {
            cuts[end] = end;
            for (int start = 0; start <= end; ++start) {
                if (palindrome[start][end]) {
                    cuts[end] = start == 0 ? 0 :
                        min(cuts[end], cuts[start - 1] + 1);
                }
            }
        }
        return cuts[n - 1];
    }
};
