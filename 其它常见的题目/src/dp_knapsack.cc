/*
 - 01背包问题，朴树解法，空间优化。 dp[c]  两重循环，for(int i=0;i<n;i++) for(int j=c;j>=w[i];j--)
 - 完全背包问题，朴树解法，空间优化。 dp[c]  两重循环，for(int i=0;i<n;i++) for(int j=0;j<=c;j++)
 - 多重背包问题，朴树解法，空间优化。 dp[c]  三层循环，for(int i=0;i<n;i++) for(int j=0;j<=c;j++)for
 - 多重背包问题，二进制优化解法，空间优化。 dp[c]  两重循环，for(int i=0;i<n;i++) for(int j=0;j<=c;j++)
 - 混合背包问题，空间优化。 dp[c]  两重循环，for(int i=0;i<n;i++) for(int j=0;j<=c;j++)

 https://leetcode.cn/problems/coin-change-ii/solutions/821592/gong-shui-san-xie-xiang-jie-wan-quan-bei-6hxv/
*/

#include <vector>
using namespace std;

int zeroOnePack(vector<int>& w,vector<int>& v,int c){
    /*
        https://mp.weixin.qq.com/s/xmgK7SrTnFIM3Owpk-emmg
        n 件商品，重量为w，价值为v，背包容量为c，求背包的最大价值

        1. 组合最优化问题,01背包
        2. 子问题：前i个商品，背包载重为j，能获得的最大价值
        3. 状态转化：dp[i][j]= max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]),j - w[i] >= 0;
        4. 观察状态转移方程，第i行格子只依赖于第i-1行的数据，可以使用滚动数组实现
        5. 进一步观察，第i行第j个格子，仅依赖于第i-1行的第j个格子，以及j-w[i]的格子。最终以优化成一为数组
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]),for j=c;j>=0;j--,j-w[i]>=0
            注意递推的顺利，从k到0
    */
    vector<int> dp(c+1,0);
    int n = w.size();
    for(int i=0;i<n;i++){
        for(int j=c;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
        }
    }
    return dp[c];
}


int completePack(vector<int>& w,vector<int>& v,int c){
    /*
        1. n种商品，每种商品重量为w，价值为v,包的容量为c,商量数量无限，求最大价值
        2. 组合优化问题，完全背包
        3. 子问题定义：前i种商品，背包容量为j，其最大价值为dp[i][j]
        4. 递推关系；
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-k*w[i]]+k*v[i]),0<=k*w[i]<=j
            dp[i][j] = max(dp[i-1][j],dp[i][j-w[i]]+v[i])
            dp[j] = max(dp[j],dp[j-w[i]]+v[i])
   */ 
    int n = w.size();
    vector<int> dp(c+1,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            int n = dp[j];
            int y = 0;;
            if(j - w[i] >= 0){
                y = dp[j-w[i]]+v[i];
            }
            dp[j] = max(n,y);
        }
    }
    return dp[c];
}



int boundedKnapsackNaive(int W, vector<int>& weight, vector<int>& value, vector<int>& count) {
    /*
        1. 多重背包
        2. n件商品，商品体积为v,价值为w,数量为s，背包的大小限制为c，求最大价值
        3. 子问题，前i种商品，背包容量为j，的最大价值
        4. 状态转移方程：
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-k*w[i]]+k*v[i]),0<=k<=s[i],0<k*w[i]<=j
    */
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int w = weight[i - 1], v = value[i - 1], c = count[i - 1];
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];
            for (int k = 1; k <= c && k * w <= j; ++k) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w] + k * v);
            }
        }
    }

    return dp[n][W];
}


// 多重背包，返回最大价值
int boundedKnapsack(int W, vector<int>& weight, vector<int>& value, vector<int>& count) {
    /*
        1. 多重背包二进制优化
        2. 将多重背包转化为01问题求解
    */
    int n = weight.size();
    vector<int> dp(W + 1, 0); // dp[j] 表示容量 j 的最大价值

    for (int i = 0; i < n; ++i) {
        int w = weight[i], v = value[i], s = count[i];
        // 二进制拆分 count[i]
        for (int k = 1; s > 0; k <<= 1) {
            int actual = min(k, s);
            s -= actual;
            int totalWeight = actual * w;
            int totalValue = actual * v;

            for (int j = W; j >= totalWeight; --j) {
                dp[j] = max(dp[j], dp[j - totalWeight] + totalValue);
            }
        }
    }
    return dp[W];
}



/*
    1. 混合背包
    2. 准变成01背包和完全背包
    3. 
        s[i] = -1，表示0,1背包
        s[i] >= 0，表示多重背包
        s[i] = -2, 表示完全背包
*/
int mixPack(vector<int>& v,vector<int>& w,vector<int>& s,int c){
    vector<int> vol;
    vector<int> worth;
    for(int i=0;i<v.size();i++){
        if(s[i] >= 0){ // 多重换成01背包
            int t = s[i];
            for(int j=1;j<=t;j*=2){
                t -= j;
                vol.push_back(v[i]*j);
                worth.push_back(w[i]*j);
            }
        }else if(s[i] == -1){ // 0,1背包
            vol.push_back(v[i]);
            worth.push_back(w[i]);
        } else if(s[i] == -2){
            vol.push_back(-v[i]);
            worth.push_back(w[i]);
        }
    }
    vector<int> dp(c+1);
    for(int i=0;i<vol.size();i++){
        if(vol[i] >= 0){ // 01背包
            for(int j=c;j>=vol[i];j--){
                // if(j-vol[i] < 0) break;
                dp[j] = max(dp[j],dp[j-vol[i]]+worth[i]);
            }
        }else{
            for(int j=vol[i];j<=c;j++){
                dp[j] = max(dp[j],dp[j-vol[i]+worth[i]]);
            }
        }
    }
    return dp[c];
}
