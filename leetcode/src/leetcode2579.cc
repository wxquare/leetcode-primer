#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums,int k){
        /*
            1. 美丽子集合的数量
            2. n = 20
            3. 时间复杂度： 2^20
        */
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int memo[n][n];
        memset(memo,-1,sizeof(memo));
        function<int(int,int,bool)> dfs = [&](int i,int pre,bool isEmpty){
            if(i == n){
                return isEmpty ? 0 : 1;
            }
            if(pre != -1 && memo[i][pre] != -1) return memo[i][pre];
            int ans = 0;
            // 不选
            ans += dfs(i+1,pre,isEmpty);
            if(pre == -1 || nums[i] - nums[pre]!=k){
                ans += dfs(i+1,i,false);
            }
            if(pre != -1) memo[i][pre] = ans;
            return ans;
        };
        return dfs(0,-1,true);
    }
};


int main(int argc, char const *argv[])
{
    vector<int> nums = {2,6,4};
    std::cout << Solution().beautifulSubsets(nums,2) << std::endl;
    return 0;
}
