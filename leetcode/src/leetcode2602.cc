/*
给你一个正整数数组 nums 。

同时给你一个长度为 m 的整数数组 queries 。第 i 个查询中，你需要将 nums 中所有元素变成 queries[i] 。你可以执行以下操作 任意 次：

将数组里一个元素 增大 或者 减小 1 。
请你返回一个长度为 m 的数组 answer ，其中 answer[i]是将 nums 中所有元素变成 queries[i] 的 最少 操作次数。

注意，每次查询后，数组变回最开始的值。



输入：nums = [3,1,6,8], queries = [1,5]
输出：[14,10]
解释：第一个查询，我们可以执行以下操作：
- 将 nums[0] 减小 2 次，nums = [1,1,6,8] 。
- 将 nums[2] 减小 5 次，nums = [1,1,1,8] 。
- 将 nums[3] 减小 7 次，nums = [1,1,1,1] 。
第一个查询的总操作次数为 2 + 5 + 7 = 14 。
第二个查询，我们可以执行以下操作：
- 将 nums[0] 增大 2 次，nums = [5,1,6,8] 。
- 将 nums[1] 增大 4 次，nums = [5,5,6,8] 。
- 将 nums[2] 减小 1 次，nums = [5,5,5,8] 。
- 将 nums[3] 减小 3 次，nums = [5,5,5,5] 。
第二个查询的总操作次数为 2 + 4 + 1 + 3 = 10 。

*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        long long sum = 0;
        int n = nums.size();
        vector<long long> prefixSum(n+1,0);
        for(int i=0;i<n;i++){
            prefixSum[i+1] = prefixSum[i] + nums[i];
            sum += nums[i];
        }
        vector<long long> ans;
        for(auto q : queries){
            auto it = upper_bound(nums.begin(),nums.end(),q);
            if(it == nums.end()){ // 没有数是大于q的
                long long t = 1L * q * n - sum;
                ans.push_back(t);
            }else if(it == nums.begin()) { // 所有数都是大于q的
                long long t = sum - 1L * q * n;
                ans.push_back(t);
            } else {
                int i = it - nums.begin();  // 前i项是<=q,后面n-i项>q
                long long t = 1L * q * i - prefixSum[i] + sum - prefixSum[i] - 1L * q * (n - i);
                ans.push_back(t);
            }
        }
        return ans;
    }
};