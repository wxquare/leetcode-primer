/*
  1. 存在n个城市，相互之间会可连通，售货员必须访问n个城市且恰好访问一次回到初始位置，求最短距离

*/

#include <vector>
using namespace std;

#define INF 10e7

int tsp(int n,vector<vector<int>>& g){
    int m = 1 << (n - 1);
    vector<vector<int>> dp(n,vector<int>(m,0));
    /*
        1. 状态压缩dp
        2. dp[i][mask] 表示从定点i到状态mask最后回到起始点的最短距离
    */
   //边界条件处理
   for(int i=0;i<n;i++){
        dp[i][0] = g[i][0];
   }
    for(int mask=1;mask<m;mask++){
        for(int i=0;i<n;i++){
            dp[i][mask] = INF;
            // 集合mask中包含节点i continue;
            if((mask & (1<<i)) == 1){
                continue;
            }
            for(int j=1;j<n;j++){  
                if((mask & (1 << j)) == 0) continue;
                if(dp[i][mask] > g[i][j] + dp[j][mask^(1<<j)]){
                    dp[i][mask] = g[i][j] + dp[j][mask^(1<<j)];
                }
            }
        }
    }
    return dp[0][m-1];
}