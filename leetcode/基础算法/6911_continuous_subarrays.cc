/*
给你一个下标从 0 开始的整数数组 nums 。nums 的一个子数组如果满足以下条件，那么它是 不间断 的：

i，i + 1 ，...，j  表示子数组中的下标。对于所有满足 i <= i1, i2 <= j 的下标对，都有 0 <= |nums[i1] - nums[i2]| <= 2 。
请你返回 不间断 子数组的总数目。

子数组是一个数组中一段连续 非空 的元素序列。
*/
#include <utility>
#include <set>
#include <vector>
#include <iostream>

using namespace std;


class lessPair{
public:
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2) const {
        if(p1.first < p2.first) return true;
        if(p1.first == p2.first) return p1.second < p2.second;
        return false;
    }
};

class greaterPair{
public:
    bool operator()(const pair<int,int>& p1,const pair<int,int>& p2) const {
        if(p1.first > p2.first) return true;
        if(p1.first == p2.first) return p1.second < p2.second;
        return false;
    }
};

class Solution {
public:

    long long continuousSubarrays(vector<int>& nums) {
        set<pair<int,int>> pq1; // 从小到大
        set<pair<int,int>,greater<pair<int,int>>> pq2; // 从大到小
        int n = nums.size();
        int i=0;
        int j =0;
        long long ans = 0;
        for(int i=0;i<n;i++){
            for(;j<n;){
                if(pq1.size() == 0 || pq2.begin()->first - pq1.begin()->first <= 2){
                    pq1.insert(make_pair(nums[j],j));
                    pq2.insert({nums[j],j});
                    j++;
                } else {
                    break;
                }
            }
            ans += pq1.size();
            if(pq2.begin()->first - pq1.begin()->first > 2){
                ans--;
            }
            pq1.erase({nums[i],i});
            pq2.erase({nums[i],i});
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> nums = {5,4,2,4};
    std::cout << Solution().continuousSubarrays(nums) << std::endl;
    return 0;
}
