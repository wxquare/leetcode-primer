class Solution {
    static const long long MOD = 1000000007;
    long long power(long long a, int e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        long long combination = 1;
        for (int i = 1; i <= k; ++i)
            combination = combination * (n - i) % MOD * power(i, MOD - 2) % MOD;
        return combination * m % MOD * power(m - 1, n - 1 - k) % MOD;
    }
};
