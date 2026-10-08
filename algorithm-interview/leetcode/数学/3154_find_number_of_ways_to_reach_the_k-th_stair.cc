class Solution {
    long long choose(int n, int k) {
        if (k < 0 || k > n) return 0;
        k = k < n - k ? k : n - k;
        long long r = 1;
        for (int i = 1; i <= k; ++i) r = r * (n - k + i) / i;
        return r;
    }

public:
    int waysToReachStair(int k) {
        long long ans = 0;
        for (int jumps = 0; jumps <= 30; ++jumps) {
            long long down = (1LL << jumps) - k;
            if (0 <= down && down <= jumps + 1) ans += choose(jumps + 1, down);
        }
        return ans;
    }
};
