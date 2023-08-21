#include <vector>
using namespace std;
class Solution{
public:
    int maximumTheProfit(int n,vector<vector<int>>& offers){
        /*
            1. 最大化利润（贪心、二分、dp或搜索）
            2. dp[i] 表式0-i的最大利润
        */
        vector<vector<vector<int>>> groups(n);
        for(auto & offer : offers) {
            groups[offer[1]].push_back(offer);
        }
        vector<int> dp(n+1);
        for(int i=0;i<n;i++){
            dp[i+1] = dp[i];
            for(auto offer : groups[i]){
                dp[offer[1]+1] = max(dp[offer[1]+1],dp[offer[0]]+offer[2]);
            }
        }
        return dp[n];
    }
};

int main(){

}