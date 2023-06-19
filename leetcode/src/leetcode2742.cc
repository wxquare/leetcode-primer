#include <vector>
#include <iostream>
using namespace std;

/*  
    题目简化： 从n个中选择k个墙面给付费师傅刷 + 付费师傅花的时间time >=n，优化使得费用最低 ßß
    1. 是否可以用选或不选解决，直接递归，时间复杂度2^n，2^500 次方肯定会TLE
       直接暴力搜索:从i开始搜索，付费墙面为j,付费时间为t的最底费用
    2. 能否用记忆化优化，是否存在重叠子问题
        将搜索状态存储在memo中，避免重复计算
        从0-i中付费时间，付费墙面数量为j,付费时间为t的最底费用
    3. 通常来说步骤2基本能解决问题，但有时需要进一步优化搜索状态
*/

// 针对付费工人，如何暴力选和不选？时间复杂度为2^n
class SolutionBF{
public:
    int painWalls(vector<int>& cost,vector<int>& time){
        int n = cost.size();
        function<int(int,int,int)> dfs = [&](int i,int k,int t){
            int ans = INT_MAX;
            if(k + t >= n) return 0;
            if(i >= n){ // 遍历到结尾不符合方案
                return INT_MAX;
            }
            int c1 = dfs(i+1,k,t);
            if(c1 < INT_MAX){
                ans = min(ans,c1);
            } 
            long long c2 = 0L + cost[i] + dfs(i+1,k+1,t+time[i]);
            if(c2 < INT_MAX){
                ans = min(ans,int(c2));
            }
            return ans;
        };
        return dfs(0,0,0);
    }
};


// 如何在暴力选和不选中加入记忆化搜索？将搜索状态保存在memo中，空间换时间时间复杂度为n^3
class SolutionMemo {
public:
    int painWalls(vector<int>& cost,vector<int>& time){
        int n = cost.size();
        int memo[n][n][n];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,int)> dfs = [&](int i,int k,int t){
            int ans = INT_MAX;
            if(k + t >= n) return 0;
            if(i >= n){ // 遍历到结尾不符合方案
                return INT_MAX;
            }
            if(memo[i][k][t] != -1) return memo[i][k][t]; 

            int c1 = dfs(i+1,k,t);
            if(c1 < INT_MAX){
                ans = min(ans,c1);
            } 
            long long c2 = 0L + cost[i] + dfs(i+1,k+1,t+time[i]);
            if(c2 < INT_MAX){
                ans = min(ans,int(c2));
            }
            memo[i][k][t] = ans;
            return ans;
        };
        return dfs(0,0,0);
    }
};


// 通常来说，记忆化搜索能够满足题目的要求，但有时状态太多，也会超时需要学会进一步压缩状态
class SolutionMemo2 {
public:
    /*
        1. 当状态很多时，需要考虑状态能否进一步缩减
    */
    int painWalls(vector<int>& cost,vector<int>& time){
        int n = cost.size();
        int memo[n][2*n]; // 从i开始，付费时间 - 不付费的差值，这里有可能为负数，需要加上偏移量
        memset(memo,-1,sizeof(memo));
        function<int(int,int)> dfs = [&](int i,int d){
            int ans = INT_MAX;
            // 后面的墙面全都可以免费刷
            if(d >= n - i + n) return 0;

            if(i >= n){ // 遍历到结尾不符合方案
                return INT_MAX;
            }
            if(memo[i][d] != -1) return memo[i][d]; 
            int c1 = dfs(i+1,d-1);
            if(c1 < INT_MAX){
                ans = min(ans,c1);
            } 
            long long c2 = 0L + cost[i] + dfs(i+1,d + time[i]);
            if(c2 < INT_MAX){
                ans = min(ans,int(c2));
            }
            memo[i][d] = ans;
            return ans;
        };
        return dfs(0,n);
    }
};







int main(int argc, char const *argv[])
{
    vector<int> cost = {1,2,3,2};
    vector<int> time = {1,2,3,2};
    std::cout << SolutionMemo2().painWalls(cost,time) << std::endl;
    return 0;
}
