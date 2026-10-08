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
    int longestCommonSubsequence(string a, string b) {
        vector<int> d(b.size() + 1);
        for (char x : a) {
            int p = 0;
            for (int j = 1; j <= b.size(); j++) {
                int q = d[j];
                d[j] = x == b[j - 1] ? p + 1 : max(d[j], d[j - 1]);
                p = q;
            }
        }
        return d.back();
    }
};
