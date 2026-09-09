#include <vector>
#include <iostream>
using namespace std;


/*
    1. 判断能否到达其中的一个0

    [4,2,3,0,3,1,2]

*/

class Solution{
public:
    bool canReach(vector<int>& nums,int start){
        int n = nums.size();
        bool ans = false;
        vector<bool> visited(n,false);

        function<void(int)> dfs = [&](int cur){
            if(cur < 0 || cur >= nums.size()) return;
            if(ans) return;
            if(visited[cur]) return;
            if(nums[cur] == 0){
                ans = true;
                return;
            }
            visited[cur] = true;
            dfs(cur+nums[cur]);
            dfs(cur-nums[cur]);
        };
        dfs(start);
        return ans;
    }
};

int main(){
    vector<int> nums = {3,0,2,1,2};
    std::cout << Solution().canReach(nums,2) << std::endl;
    return 0;
}