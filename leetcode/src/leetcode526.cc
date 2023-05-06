/*
    假设有从 1 到 n 的 n 个整数。用这些整数构造一个数组 perm（下标从 1 开始），只要满足下述条件 之一 ，该数组就是一个 优美的排列 ：
    - perm[i] 能够被 i 整除
    - i 能够被 perm[i] 整除
    给你一个整数 n ，返回可以构造的 优美排列 的 数量 。

    1 <= n <= 15


    输入：n = 2
    输出：2
    解释：
    第 1 个优美的排列是 [1,2]：
        - perm[1] = 1 能被 i = 1 整除
        - perm[2] = 2 能被 i = 2 整除
    第 2 个优美的排列是 [2,1]:
        - perm[1] = 2 能被 i = 1 整除
        - i = 2 能被 perm[2] = 1 整除
*/


// class Solution {
// public:
//     int countArrangement(int n) {
//         vector<int> f(1 << n);
//         f[0] = 1;
//         for (int mask = 1; mask < (1 << n); mask++) {
//             int num = __builtin_popcount(mask);
//             for (int i = 0; i < n; i++) {
//                 if (num % (i + 1) == 0 || (i + 1) % num == 0) {
//                     f[mask] += f[mask ^ (1 << i)];
//                 }
//             }
//         }
//         return f[(1 << n) - 1];
//     }
// };


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countArrangement(int n) {
        /*
            1. 状态压缩dp
            2. 子问题：dp[i][state],表示前i个数状态为state的方案数量
            3. 状态转化方程：
                dp[i][state] = dp[i-1][state]
        */
        int m = 1 << n; // n个数
        vector<vector<int>> dp(n+1,vector<int>(m,0));
        dp[0][0] = 1;
        for(int i=1;i<=n;i++){
            for(int mask=1;mask<m;mask++){
                for(int j=0;j<n;j++){
                    if((mask & (1 << j)) == 0) continue;
                    if(i % (j+1) == 0 || (j+1) % i == 0){
                        dp[i][mask] += dp[i-1][mask ^ (1<<j)];
                    }
                }
            }
        }
        return dp[n][m-1];
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().countArrangement(4) << std::endl;
    return 0;
}
