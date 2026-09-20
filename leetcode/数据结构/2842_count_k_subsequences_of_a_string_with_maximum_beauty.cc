#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countKSubsequencesWithMaxBeauty(string s, int k) {
        vector<int> c(26);
        for (char x : s) c[x - 'a']++;
        sort(c.rbegin(), c.rend());
        if (k > 26 || c[k - 1] == 0) return 0;
        long long r = 1;
        int need = 0;
        for (int i = 0; i < k; i++) r = r * c[i] % 1000000007, need += c[i] == c[k - 1];
        int avail = 0;
        for (int x : c)
            if (x == c[k - 1]) avail++;
        for (int i = 0; i < need; i++) r = r * (avail - i) % 1000000007;
        for (int i = 2; i <= need; i++) r = r * modpow(i, 1000000005) % 1000000007;
        return r;
    }

private:
    long long modpow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = r * a % 1000000007;
            a = a * a % 1000000007;
            b >>= 1;
        }
        return r;
    }
};
