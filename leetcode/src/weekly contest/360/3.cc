
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums,int target){
        /*
            1. 最小操作次数，1，1，2，16，32  =》 21
        */

        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        if(sum < target) return -1;
        sort(nums.begin(),nums.end());
        int ans = 0;
        while(target > 0){
            if(nums.back() > target){
                if(sum - nums.back() >= target){
                    nums.pop_back();
                } else {
                    ans++;
                    int t = nums.back();
                    t >>= 1;
                    nums.push_back(t);
                }
            } else {
                target -= nums.back();
                sum -= nums.back();
                nums.pop_back();
            }
        }
        return ans;
    }
};