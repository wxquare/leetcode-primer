#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;


// 预处理
const int MX = 2 * 1e6;
bool isSquare[MX+1];
int init = []()->int {
    for(int i = 1; i * i <= MX; i++) {
        isSquare[i * i] = true;
    }
    return 0;
}();


// 全排列，时间复杂度为O(n!)
class SolutionBF {
public:
    int numSquarefulPerms(vector<int>& nums){
        int n = nums.size();
        vector<int> vis(n,false);
        function<int(int,int)> dfs = [&](int i,int pre){
            if(i == n){
                return 1;
            }
            int ans = 0;
            for(int j=0;j<n;j++){
                if(vis[j]) continue;
                if(isSquare[nums[pre]+nums[i]]){
                    vis[j] = true;
                    ans += dfs(i+1,j);
                    vis[j] = false;
                }
            }
            return ans;
        };
        int ans = 0;
        for(int i=0;i<n;i++){
            vis[i] = true;
            ans += dfs(1,i);
            vis[i] = false;
        }
        return ans;
    }
};

// 记忆化搜索 + 状态压缩，n*(2^n)
// 预处理
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums){
        int n = nums.size();
        int memo[1<<n][n];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,int)> dfs = [&](int i,int mask,int pre){
            if(i == n){
                return 1;
            }
            int ans = 0;
            unordered_set<int> vis;
            for(int j=0;j<n;j++){
                if((mask & (1 << j)) != 0) continue;
                if(isSquare[nums[j]+nums[pre]] == false) continue;
                if(vis.count(nums[j])) continue;
                vis.insert(nums[j]);
                ans += dfs(i+1, mask|(1<<j),j);
            }
            return ans;
        };
        int ans = 0;
        int mask = 0;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(vis.count(nums[i])) continue;
            vis.insert(nums[i]);
            ans += dfs(1,mask|(1 << i),i);
        }
        return ans;
    }
};



int main(int argc, char const *argv[])
{   
    vector<int> nums = {1,17,8};
    std::cout << Solution().numSquarefulPerms(nums) << std::endl;
    return 0;
}
