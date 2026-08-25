#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

// ==================== 1. 基础单次计算 (适合小数据/不取模) ====================
// 适用于 n <= 62，结果可以用 long long 装下的情况
// 时间复杂度: O(k)，空间复杂度: O(1)
i64 C_small(i64 n, i64 k) {
    if (k < 0 || k > n) return 0;
    if (k == 0 || k == n) return 1;
    if (k > n / 2) k = n - k;
    
    i64 res = 1;
    for (int i = 1; i <= k; ++i) {
        res = res * (n - i + 1) / i;
    }
    return res;
}

// ==================== 2. 动态规划杨辉三角 (适合多次小范围查询) ====================
// 适用于 N <= 2000，取模或不取模均可
// 预处理 O(N^2)，单次查询 O(1)
const int MAXN_DP = 2005;
const i64 MOD_DP = 1e9 + 7; // 如果不需要取模，可去掉 % MOD_DP
i64 C_dp[MAXN_DP][MAXN_DP];

void init_pascal() {
    for (int i = 0; i < MAXN_DP; ++i) {
        C_dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C_dp[i][j] = (C_dp[i - 1][j] + C_dp[i - 1][j - 1]) % MOD_DP;
        }
    }
}

// ==================== 3. 阶乘+逆元法 (竞赛最常用/主力模板) ====================
// 适用于 N <= 10^6，模数为大质数 (如 1e9+7, 998244353)
// 预处理 O(N)，单次查询 O(1)
namespace CombMod {
    const int MAXN = 1000005;
    const i64 MOD = 1e9 + 7; // 可根据题目修改为 998244353 等

    i64 fact[MAXN], invFact[MAXN];

    // 快速幂
    i64 qpow(i64 base, i64 exp) {
        i64 res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

    // 逆元 (费马小定理)
    i64 modInverse(i64 n) {
        return qpow(n, MOD - 2);
    }

    // O(N) 预处理阶乘与阶乘逆元
    void init() {
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i < MAXN; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        // 线性求阶乘逆元技巧：先求最大阶乘的逆元，再倒推
        invFact[MAXN - 1] = modInverse(fact[MAXN - 1]);
        for (int i = MAXN - 2; i >= 1; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    // 查询 C(n, k) % MOD
    i64 C(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    // 排列数 A(n, k) % MOD
    i64 A(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[n - k] % MOD;
    }
}

// ==================== 4. Lucas 定理 (超大范围取模) ====================
// 适用于 n, k <= 10^18，但模数 P 较小且为质数 (如 P <= 10^5)
// 复杂度: O(P + log_P(N))
namespace Lucas {
    i64 P = 100003; // 小质数模数

    i64 qpow(i64 a, i64 b, i64 p) {
        i64 res = 1;
        a %= p;
        while (b) {
            if (b & 1) res = res * a % p;
            a = a * a % p;
            b >>= 1;
        }
        return res;
    }

    // 小数据下的 C(n, k) % p
    i64 C_small_mod(i64 n, i64 k, i64 p) {
        if (k > n) return 0;
        i64 num = 1, den = 1;
        for (int i = 1; i <= k; ++i) {
            num = num * (n - i + 1) % p;
            den = den * i % p;
        }
        return num * qpow(den, p - 2, p) % p;
    }

    // Lucas 递归计算
    i64 lucas(i64 n, i64 k, i64 p) {
        if (k == 0) return 1;
        return C_small_mod(n % p, k % p, p) * lucas(n / p, k / p, p) % p;
    }
}

// ==================== 测试示例 ====================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1. 初始化逆元模板
    CombMod::init();
    cout << "CombMod C(10, 3): " << CombMod::C(10, 3) << "\n"; // 输出 120
    cout << "CombMod A(10, 3): " << CombMod::A(10, 3) << "\n"; // 输出 720

    // 2. 初始化 DP 模板
    init_pascal();
    cout << "DP C(10, 3): " << C_dp[10][3] << "\n";            // 输出 120

    // 3. Lucas 定理
    cout << "Lucas C(10^18, 10^9): " << Lucas::lucas(1e18, 1e9, 100003) << "\n";

    return 0;
}
