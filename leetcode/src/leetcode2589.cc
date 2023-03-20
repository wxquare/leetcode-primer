
/*
给你一个下标从 0 开始的整数数组 nums 和一个整数 value 。

在一步操作中，你可以对 nums 中的任一元素加上或减去 value 。

例如，如果 nums = [1,2,3] 且 value = 2 ，你可以选择 nums[0] 减去 value ，得到 nums = [-1,2,3] 。
数组的 MEX (minimum excluded) 是指其中数组中缺失的最小非负整数。

例如，[-1,2,3] 的 MEX 是 0 ，而 [1,0,3] 的 MEX 是 2 。
返回在执行上述操作 任意次 后，nums 的最大 MEX 。


输入：nums = [1,-10,7,13,6,8], value = 5
输出：4
解释：执行下述操作可以得到这一结果：
- nums[1] 加上 value 两次，nums = [1,0,7,13,6,8]
- nums[2] 减去 value 一次，nums = [1,0,2,13,6,8]
- nums[3] 减去 value 两次，nums = [1,0,2,3,6,8]
nums 的 MEX 是 4 。可以证明 4 是可以取到的最大 MEX 。


1 <= nums.length, value <= 10e5
-10e9 <= nums[i] <= 10e9

*/

#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        /*
            nums = [1,-10,7,13,6,8], value = 5
            0: 1
            1: 1+1
            2: 1
            3: 1+1
            4:
        */
        vector<int> r(value,0);
        for(int num : nums){
            int a = num % value;
            a = a < 0 ? a + value : a;
            r[a]++;
        }

        int minValue = r[0];
        int minIndex = 0;

        for(int i=1;i<r.size();i++){
            if(r[i] < minValue){
                minValue = r[i];
                minIndex = i;
            }
        }
        return minValue * value + minIndex;
    }
};

int main(int argc, char const *argv[]){
    vector<int> nums = {1,3,5,7};
    std::cout << Solution().findSmallestInteger(nums,2) << std::endl;
    return 0;
}
