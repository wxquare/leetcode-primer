
#include <vector>
#include <iostream>
using namespace std;

/*
    差分数组是一种常用的数据结构，用于高效处理数组的区间增减操作。它可以在 O(1) 的时间内完成区间增减操作，而不需要修改原始数组的每个元素
*/

// 原数组:  [1,4,5,6,3]
// 差分数组: [1,3,1,1,-3]
// 差分数组的前缀和是: [1,4,5,6,3]
// 差分数组区间增加一个值，例如在[2，4]区间加上 diff[start] += 3,diff[end+1] -=3
void difference(){
    vector<int> nums = {1,4,5,6,4}; //原数组
    int n = nums.size();
    // 由原数组创建diff数组
    vector<int> diff(n);
    diff[0] = nums[0];
    for(int i=1;i<n;i++){
        diff[i] = nums[i] - nums[i-1];
    }

    // 在区间[2,4]中每个数加上3
    diff[2] += 3;
    diff[4+1] -= 3;

    // 由差分数组返回原数组
    vector<int> ans(n,0);
    ans[0] = diff[0];
    for(int i=1;i<n;i++){
        ans[i] = diff[i] + diff[i-1];
    }
}