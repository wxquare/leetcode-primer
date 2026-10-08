#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    long long countPalindromePaths(vector<int>& p, string s) {
        long long r = 0;
        for (int i = 1; i < p.size(); i++) {
            int a = i, b = p[i], x = 0;
            while (b >= 0) {
                x ^= 1 << (s[b] - 'a');
                b = p[b];
            }
            r += __builtin_popcount((unsigned)x) <= 1;
        }
        return r;
    }
};
