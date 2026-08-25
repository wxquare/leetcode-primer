/*

2560. 打家劫舍 IV

沿街有一排连续的房屋。每间房屋内都藏有一定的现金。现在有一位小偷计划从这些房屋中窃取现金。

由于相邻的房屋装有相互连通的防盗系统，所以小偷 不会窃取相邻的房屋 。

小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额 。

给你一个整数数组 nums 表示每间房屋存放的现金金额。形式上，从左起第 i 间房屋中放有 nums[i] 美元。

另给你一个整数 k ，表示窃贼将会窃取的 最少 房屋数。小偷总能窃取至少 k 间房屋。

返回小偷的 最小 窃取能力。
*/

#include <vector>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int left = 1,right = 1e9;
        int ans = 1e9;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int cnt = 0;
            for(int i=0;i<nums.size();){
                if(nums[i] <= mid){
                    cnt++;
                    i += 2;
                } else {
                    i += 1;
                }
            }
            if(cnt >= k){
                ans = min(ans,mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
        
    }
};