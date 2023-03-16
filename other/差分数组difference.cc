
#include <vector>
#include <iostream>
using namespace std;

/*

*/

vector<int> difference(vector<int>& nums,vector<vector<int>>& updates){
    int n = nums.size();
    vector<int> d(n,0);
    for(int i=0;i<n;i++){
        d[i] += nums[i];
        if(i + 1 < n){
            d[i+1] -= nums[i];
        }
    }

    // 区间增加一个值
    for(auto & update : updates){
        int l = update[0];
        int r = update[1];
        int v = update[2];
        d[l] += v;
        if(r + 1 < n) d[r+1] -= v;
    }

    vector<int> ans(n,0);
    ans[0] = d[0];
    for(int i=1;i<nums.size();i++){
        ans[i] += ans[i-1] + d[i];
    }
    return ans;
}



int main(int argc, char const *argv[]){
    vector<int> nums = {1,2,3,4,5};
    vector<vector<int>> updates = {{2,3,5}};
    vector<int> ans = difference(nums,updates);
    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
