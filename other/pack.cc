





/*
 01背包问题
 完全背包问题

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
        for(int j=c;j>=0;j--){
            if(j - w[i] >= 0){
                dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
            }
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
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-k*w[i]]+k*v[i]),0<=k*v[i]<=j
            dp[i][j] = max(dp[i-1][j],dp[i][j-w[i]]+v[i])
            dp[j] = max(dp[j],dp[j-w[i]]+v[i])
   */ 
    int n = w.size();
    vector<int> dp(c+1,0);
    for(int i=0;i<<n;i++){
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



int multiplePack(vector<int>& w,vector<int>& v,vector<int>& s,int c) {
    /*
        1. 多重背包
        2. n件商品，商品体积为v,价值为w,数量为s，背包的大小限制为c，求最大价值
        3. 子问题，前i种商品，背包容量为j，的最大价值
        4. 状态转移方程：
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-k*w[i]]+k*v[i]),0<=k<=s[i],0<k*w[i]<=j
    */
    vector<int> dp(c+1,0);
    int n = v.size();
    for(int i=0;i<n;i++){
        for(int j=c;j>=0;j--){
            for(int k=0;i<=s[i];i++){
                if(j - v[i] > 0) break;
                dp[j] = max(dp[j],dp[j-w[i]*k]+k*v[i]);
            }
        }
    }
    return dp[c];
}


/*
    1. 多重背包二进制优化
    2. 将多重背包转化为01问题求解
*/
int multiplePackBinaryOpt(vector<int>& v,vector<int>& w,vector<int>& s,int c){
    vector<int> v1;
    vector<int> w1;
    for(int i=0;i<v.size();i++){
        int val = s[i];
        for(int j=1;j<val;j*=2){
            val -=j;
            v1.push_back(j*v[i]);
            w1.push_back(j*w[i]);
        }
        if(val > 0){
            v1.push_back(val*v[i]);
            w1.push_back(val*w[i]);
        }
    }
    int n2 = v1.size();
    vector<int> dp(c+1,0);
    for(int i=0;i<v1.size();i++){
        for(int j=c;j>=0;j--){
            if(j<v1[i]) break;
            dp[j] = max(dp[j],dp[j-v1[i]]+w1[i]);
        }
    }
    return dp[c];
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
