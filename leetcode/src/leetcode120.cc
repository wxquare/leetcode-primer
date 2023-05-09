#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    int minimumTotal(vector<vector<int>> triangle){
        /*  
            1. dp
            2. 状态表示和子问题：dp[i] 表示从顶到i行的最大路径和
            3. dp[i][j] = max(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
            4. 观察转移方程： 
                a.第i行仅仅依赖于第i-1行的结果
                b. 仅仅依赖于第j-1列和j列
                
                dp[j] = max(dp[j],dp[j-1]) + triangle[i][j];
        */
        int n = triangle.size();
        vector<int> dp(n,0);
        dp[0] = triangle[0][0];
        for(int i=1;i<n;i++){
            for(int j=i;j>=0;j--){
                dp[j] = max(dp[j],j>0?dp[j-1]:0) + triangle[i][j];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7}};
    std::cout << Solution().minimumTotal(triangle) << std::endl;
    return 0;
}
