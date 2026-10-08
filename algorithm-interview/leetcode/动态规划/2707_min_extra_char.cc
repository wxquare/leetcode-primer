#include <string>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) { 
        /*
            1. 记忆化搜索memo
        */
        unordered_set<string> m(dictionary.begin(),dictionary.end());
        int n = s.length();
        vector<int> memo(n,-1);
        function<int(int)> dfs = [&](int start)->int{
            if(start == n){
                return 0;
            }
            if(memo[start] != -1){
                return memo[start];
            }
            int ans = n;
            for(int i=start;i<n;i++){
                for(int j=i;j<n;j++){
                    if(m.count(s.substr(i,j-i+1))){
                        ans = min(ans,i-start+dfs(j+1));
                    }
                }
                ans = min(ans,i-start+1+dfs(i+1));
            }
            memo[start] = ans;
            return ans;
        };
        return dfs(0);
    }
};



class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        /*
            1. dp
            2. 子问题：从0到i的最少剩下多少个字符
            3. 状态转移  
                dp[i] = min(dp[i-1]+1,dp[i]);
                dp[i] = min(dp[j],dp[i]),(0<=j<=i, s[j:i] 在dictory中)
            4. 边界状态转移
                由于存在-1的操作，index+1操作
        */
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        int n = s.size();
        vector<int> dp(n + 1,n);
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = min(dp[i+1],dp[i] + 1);            //不选
            for (int j = 0; j <= i; ++j) {
                if (dict.count(s.substr(j, i - j + 1))) {   //分割
                    dp[i + 1] = min(dp[i + 1], dp[j]);
                }
            }
        }
        return dp[n];
    }
};