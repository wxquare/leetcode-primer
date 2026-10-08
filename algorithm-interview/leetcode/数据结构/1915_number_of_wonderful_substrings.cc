#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    long long wonderfulSubstrings(string s) {
        long long r = 0;
        long long c[1 << 10] = {};
        c[0] = 1;
        int x = 0;
        for (char z : s) {
            x ^= 1 << (z - 'a');
            r += c[x]++;
            for (int j = 0; j < 10; j++) r += c[x ^ (1 << j)];
        }
        return r;
    }
};
