
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


