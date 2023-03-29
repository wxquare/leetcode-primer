/*
2601. 质数减法运算

给你一个下标从 0 开始的整数数组 nums ，数组长度为 n 。

你可以执行无限次下述运算：

选择一个之前未选过的下标 i ，并选择一个 严格小于 nums[i] 的质数 p ，从 nums[i] 中减去 p 。
如果你能通过上述运算使得 nums 成为严格递增数组，则返回 true ；否则返回 false 。

严格递增数组 中的每个元素都严格大于其前面的元素。

输入：nums = [4,9,6,10]
输出：true
解释：
在第一次运算中：选择 i = 0 和 p = 3 ，然后从 nums[0] 减去 3 ，nums 变为 [1,9,6,10] 。
在第二次运算中：选择 i = 1 和 p = 7 ，然后从 nums[1] 减去 7 ，nums 变为 [1,2,6,10] 。
第二次运算后，nums 按严格递增顺序排序，因此答案为 true 。


提示：

1 <= nums.length <= 1000
1 <= nums[i] <= 1000
nums.length == n
*/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> primes;
    bool init = false;
    bool primeSubOperation(vector<int>& nums) {
        // 初始化1000以内的所有质数
        if(init == false){
            vector<bool> isPrime(1000+1,true);
            for(int i=2;i<=1000;i++){
                if(isPrime[i]){
                    primes.push_back(i);
                    for(int j=i*i;j<=1000;j+=i){
                        isPrime[j] = false;
                    }
                }
            }
        }
        // 从前向后遍历，保留当前最大值
        int curMax = 0;
        for(int i=0;i<nums.size();i++){
            // 大于或等于nums[i] - curMax,题目要求是严格小于
            if(nums[i] <= curMax) return false;
            // 在primes 中找到一个最大的prime，nums[i]- prime > curMax,nums[i] - curMax > prime
            // prime < nums[i] - curMax
            auto it = lower_bound(primes.begin(),primes.end(),nums[i] - curMax);
            if(it == primes.begin()){
                curMax = nums[i]; // 不存在这样的prim
                continue;
            }
            it--;
            curMax = nums[i] - *it;
        }
        return true; 
    }
};


int main(){
    vector<int> nums = {998,2};
    std::cout << Solution().primeSubOperation(nums) << std::endl;
}