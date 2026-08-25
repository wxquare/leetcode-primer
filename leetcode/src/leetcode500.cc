/*
    1. 最长回文字符串的长度


    给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

    子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。


    输入：s = "bbbab"
    输出：4
    解释：一个可能的最长回文子序列为 "bbbb" 。
*/


#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*
            1. 动态规划
            2. 子问题：dp[i][j] 表示从i到j最长回文子序列的长度
            dp[i][j] = max(dp[i][j-1],dp[i+1][j],dp[i+1][j-1]+ s[i] == s[j] ? 2 : 0);
        */
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i][j] = max(dp[i][j],dp[i+1][j]);
                dp[i][j] = max(dp[i][j],dp[i][j-1]);
                dp[i][j] = max(dp[i][j],dp[i+1][j-1] + (s[i] == s[j] ? 2 : 0));
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    std::cout << Solution().longestPalindromeSubseq("bbbab") << std::endl;
}