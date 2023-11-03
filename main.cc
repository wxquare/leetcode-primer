#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;



int minDistance(string s1,string s2){

    /*
        a,b,c
        b,c
    */
    int n1 = s1.length();
    int n2 = s2.length();
    int memo[n1][n2];
    memset(memo,-1,sizeof(memo));
    function<int(int,int)> dfs = [&](int i,int j)->int{
        if(i >= n1) return n2 - j;
        if(j >= n2) return n1 - i;

        if(memo[i][j] != -1){
            return memo[i][j];
        }
        int ans = max(n1-i,n2-j);
        if(s1[i] == s2[j]){
            ans = min(ans,dfs(i+1,j+1));
        }else{
            ans = min(min(dfs(i+1,j),dfs(i,j+1)),dfs(i+1,j+1)) + 1;
        }
        memo[i][j] = ans;
        return ans;
    };
    return dfs(0,0);
}


int miniDistance_DP(string& s1,string& s2){
    int n1 = s1.length();
    int n2 = s2.length();
    vector<vector<int>> dp(n1+1,vector<int>(n2+1));
    // 处理边界条件
    for(int i=0;i<=n2;i++){
        dp[n1][i] = n2 - i;
    }
    for(int i=0;i<=n1;i++){
        dp[i][n2] = n1 - i;
    }
    for(int i=n1-1;i>=0;i--){
        for(int j=n2-1;j>=0;j--){
            dp[i][j] = max(n1-i,n2-j);
            if(s1[i] == s2[j]){
                dp[i][j] = max(dp[i][j],dp[i+1][j+1]);
            } else {
                dp[i][j] = max(dp[i+1][j+1]+1,dp[i][j]);// 改一个字符
                dp[i][j] = max(dp[i+1][j]+1,dp[i][j]);
                dp[i][j] = max(dp[i][j+1]+1,dp[i][j]);
            }
        }
    }
    return dp[0][0];
}




int main(){
    std::cout << minDistance("abc","ab") << std::endl;
}