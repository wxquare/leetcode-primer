/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。



输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        int first = nums[start], second = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; i++) {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }

    int rob(vector<int>& nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        return max(robRange(nums, 0, length - 2), robRange(nums, 1, length - 1));
    }
};*/

#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        /*
            1. 循环问题
        */
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int> v1(nums.begin(),nums.end()-1);
        vector<int> v2(nums.begin()+1,nums.end());
        function<int(vector<int>&)> f = [&](vector<int>& v){
            int size = v.size();
            int nopick = 0;
            int pick = v[0];
            for(int i=1;i<size;i++){
                int t = nopick;
                nopick = max(nopick,pick);
                pick = t+v[i];
                
            }
            int ans = max(nopick,pick);
            return ans;
        };
        return max(f(v1),f(v2));
    }
};

int main(){
    vector<int> nums = {2,3,2};
    std::cout << Solution().rob(nums) << std::endl;
}