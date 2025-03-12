#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> permute(int n, long long k) {
            // fac[i]：i 的阶乘
        long long fac[n + 1];
        fac[0] = 1;
        for (int i = 1; i <= n; i++) {
            fac[i] = min(fac[i - 1] * i, k + 1);
        }

        bool used[n + 1];
        memset(used, 0, sizeof(used));
        // now：现在该填偶数还是奇数，-1 表示还不确定（n 为偶数时，第一位可以填任意数）
        int now = (n & 1 ? 1 : -1);
        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            int rem = n - i;
            // 计算剩下 n - i 个数任意组合，能产生几种方案
            __int128 t;
            if (rem & 1) {
                t = __int128(1) * fac[(rem + 1) / 2] * fac[rem / 2];
            } else {
                t =  __int128(1) * fac[rem / 2] * fac[rem / 2];
            }
            // 我们需要填第 x 小的数
            long long x = (k + t - 1) / t;
            // 第 i 位填第 x 小的数，也就是说我们跳过了 t(x - 1) 种方案，
            // 那么要算出剩下的 n - i 位中，第 k - t(x - 1) 大的方案
            k -= t * (x - 1); // 
            // 通过枚举找出第 x 小的能填的数
            for (int j = 1; j <= n; j++) {
                if (!used[j] && (now == -1 || j % 2 == now)) {
                    x--;
                    if (x == 0) {
                        used[j] = true;
                        // 下一位的奇偶性和这一位相反
                        now = 1 - (j % 2);
                        ans.push_back(j);
                        break;
                    }
                }
            }
            // 找不到第 x 小的数，无解
            if (x > 0) {
                return {};
            }
        }
        return ans;
    }
};


int main(){
    // cbaabc
    // 2,3 1,4

    // std::cout << hasSameDigits() << std::endl;

    // 9223372036854775807
    std::cout << LONG_MAX << std::endl;
}