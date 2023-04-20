





/*
 01背包问题
 完全背包问题

 https://leetcode.cn/problems/coin-change-ii/solutions/821592/gong-shui-san-xie-xiang-jie-wan-quan-bei-6hxv/
*/



#include <vector>
using namespace std;
/*
    n 件商品，重量为w，价值为v，背包的大小为k，求背包的最大价值
*/
int zeroOneBackPack1(vector<int>& w,vector<int>& v,int k){
    
    /*
    https://mp.weixin.qq.com/s/xmgK7SrTnFIM3Owpk-emmg
        1. 最优问题
        2. 01背包
        3. 子问题：前i个商品，背包载重为k，能获得的最到价值
        4. 边界处理
        5. 状态转换
    */
    int n = w.size();
    vector<vector<int>> dp(n,vector<int>(k+1,0));
    for(int i=0;i<=k;i++){
        if(i >= w[0]){
            dp[0][i] = v[0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = max(dp[i][j],dp[i-1][j]);
            if(j-w[i] >= 0){
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]]+v[i]);  // pick i
            }
        }
    }
    return dp[n-1][k];
}

// 一维空间优化
int zeroOnbackPack2(vector<int>& w,vector<int>& v,int k){
    int n = w.size();
    vector<int> dp(k+1,0);
    for(int i=0;i<n;i++){
        for(int j=k;j>=0;j--){
            int n = dp[j];
            int y = dp[j-k] + v[i];
            dp[j] = max(n,y);
        }
    }
    return dp[k];
}


// 完全背包