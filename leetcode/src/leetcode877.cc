/*
    Alice 和 Bob 用几堆石子在做游戏。一共有偶数堆石子，排成一行；每堆都有 正 整数颗石子，数目为 piles[i] 。

    游戏以谁手中的石子最多来决出胜负。石子的 总数 是 奇数 ，所以没有平局。

    Alice 和 Bob 轮流进行，Alice 先开始 。 每回合，玩家从行的 开始 或 结束 处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中 石子最多 的玩家 获胜 。

    假设 Alice 和 Bob 都发挥出最佳水平，当 Alice 赢得比赛时返回 true ，当 Bob 赢得比赛时返回 false 。


    2 <= piles.length <= 500
    piles.length 是 偶数
    1 <= piles[i] <= 500
    sum(piles[i]) 是 奇数


    输入：piles = [5,3,4,5]
    输出：true
    解释：
    Alice 先开始，只能拿前 5 颗或后 5 颗石子 。
    假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
    如果 Bob 拿走前 3 颗，那么剩下的是 [4,5]，Alice 拿走后 5 颗赢得 10 分。
    如果 Bob 拿走后 5 颗，那么剩下的是 [3,4]，Alice 拿走后 4 颗赢得 9 分。
    这表明，取前 5 颗石子对 Alice 来说是一个胜利的举动，所以返回 true 。


    输入：piles = [3,7,2,3]
    输出：true
*/

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
using namespace std;

class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*
            1.区间dp
            
            2. dp[i][j] 表示从i到j alice最多能获得的石子数量
                
                dp[i][j] = max((sum(i+1,j) - dp[i+1][j]) + piles[i],(sum(i,j-1) - dp[i][j-1]) + piles[j])
                    1. alice 拿左边
                    2. alice 拿左右
        */
        int n = piles.size();

        vector<vector<int>> dp(n,vector<int>(n,0));

        vector<int> prefix(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] + piles[i];
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(i == j){
                    dp[i][j] = piles[i];
                }else if(j - i == 1){
                    dp[i][j] = max(piles[i],piles[j]);
                } else {
                    dp[i][j] = max(prefix[j+1] - prefix[i+1] - dp[i+1][j] + piles[i],prefix[j] - prefix[i] - dp[i][j-1]+piles[j]);
                }
            }
        }
        return dp[0][n-1] * 2 > prefix.back();
    }
};


int main(int argc, char const *argv[])
{
    vector<int> piles = {10,7,2,6};
    std::cout << Solution().stoneGame(piles) << std::endl;
    return 0;
}
