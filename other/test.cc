
#include <vector>
#include <string>

using namespace std;

int zeroOnePack(vector<int>& w,vector<int>& v,int c){
    /*
        1. 0、1背包选和不选类别的dp问题，
        2. dp[i][j] 表示前i个商品，容量为j的最大价值
        3. 状态转移方程以及优化
            dp[i][j] = max(dp[i-1][j],dp[i-1][j-w[i]]+v[i])
            观察状态转移方程：只依赖于前一行的前半部分
            因此可以优化为dp[j] = max(dp[j],dp[j-w[i]]),逆序
    */
    int n = w.size();
    vector<int> dp(c+1,0);
    for(int i=0;i<n;i++){
        for(int j=c;j>=0;j--){
            if(j - w[i] < 0) continue;
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    return dp[c];
}

int completePack(vector<int>& w,vector<int>& v,int c){
    int n = w.size();
    /*
        1. 完全背包，枚举类型的DP问题
        2. dp[i][j] 表示前i种商品，容量为j的最大价值
            dp[i][j] = max(dp[i-1][j-k*w[i]]+k*v[i],dp[i][j]);
    */

    int n = w.size();
    vector<int> dp(n+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j - w[i] < 0) continue;
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    return dp[n];
}


int multiplePack(vector<int>& w,vector<int>& v,vector<int>& s,int c){
    int n = w.size();
    /*
        1. 完全背包，枚举类型的DP问题
        2. dp[i][j] 表示前i种商品，容量为j的最大价值
            dp[i][j] = max(dp[i-1][j-k*w[i]]+k*v[i],dp[i][j]);
    */
    int n = w.size();
    vector<int> dp(n+1);
    for(int i=0;i<n;i++){
        for(int j=c;j>=0;j++){
            for(int k=0;k<=s[i];k++){
                dp[j] = max(dp[j],dp[j-k*w[i]]+k*v[i]);
            }
        }
    }
    return dp[n];
}

class Solution{
public:
    string longestPalindrome(string s){
        /*
            1. 区间dp
            dp[i][j] = 
        */
        int n = s.length();
        string ans = "";
        vector<vector<int>> dp(n,vector<int>(n,1));
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = dp[i][j-1];
                if(s[i] == s[j] && dp[i+1][j-1] == j-1-i-1+1){
                    dp[i][j] = max(dp[i][j-1],j-1-i-1+1 + 2);
                }
                string t = s.substr(i,j-i+1);
                if(t.length() > s.length()){
                    ans = t;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums){
        // 双指针
        int i = 0;
        int sum = 0;
        int ans = 0;
        for(int j=0;j<nums.size();j++){
            sum += nums[i];
            if(sum <= 0){
                i = j + 1;
                sum = 0;
            } else {
                ans = max(ans,sum);
            }
        }
        return ans;
    }
};


class Solution {
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        vector<int> suffix(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i] = max(suffix[i+1],prices[i]);
        }
        int ans = 0;    
        for(int i=0;i<n;i++){
            ans = max(ans,suffix[i+1] - prices[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(prices[i+1] > prices[i]){
                ans = ans + prices[i+1] - prices[i];
            }
        }
        return ans;
    }
};



class Solution{
public:
    int maxProfit(vector<int>& prices,int k){
        /*
            1. 最多允许k次交易的最大利润
            dp[i][j][0]:前i天，最大交易次数为j，且手里有股票最大利润
            dp[i][j][1]:前i天，最大交易次数为j，且手里没有股票最大利润
        */

        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,0)));

        for(int j=0;j<=k;j++){
            dp[0][j][0] = 0;
            dp[0][j][1] = -prices[0];
        }

        for(int i=1;i<n;i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = max(-prices[i],dp[i-1][0][1]);
        }

        // 状态转移
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j][0] = max(dp[i-1][j][0],dp[i-1][j-1][1] + prices[i]);
                dp[i][j][1] = max(dp[i-1][j][1],dp[i-1][j][0] - prices[i]);
            }
        }
        return dp[n-1][k][0];
    }
};


class Solution{
public:
    int maxProfit(vector<int>& prices){
        /*
            1. 包含冷冻期1天，卖出股票后需要隔一天才能买入
            2. 不包含冷冻期时

            1，3，2，1，4
            1. 有股票  == 0 
            2. 没有股票且(这一天刚卖） == 1
            3. 没有股票且(且不是刚卖股票） ==2
        */
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
        }
        return max(dp[n][1],dp[n][2]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices){
        /*
            1. 包含冷冻期1天，卖出股票后需要隔一天才能买入
            2. 不包含冷冻期时

            1，3，2，1，4
            1. 有股票  == 0 
            2. 没有股票且(这一天刚卖） == 1
            3. 没有股票且(且不是刚卖股票） ==2
        */
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(3,0));
        dp[0][0] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][2] - prices[i]);
            dp[i][1] = dp[i-1][0]+prices[i];
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]);
        }
        return max(dp[n][1],dp[n][2]);
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices,int fee){
        /*
            1. 包含手续费
            1，3，4，3，8，8，4，9
            2，，6，5

            dp[i][0]: 表示i且没有股票的最大利润
            dp[1][1]: 表示i且有股票的最大利润
        */
        int n = prices.size();

        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1;i<n;i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0] - prices[i]);
        }
        return dp[n-1][0];
    }
}


