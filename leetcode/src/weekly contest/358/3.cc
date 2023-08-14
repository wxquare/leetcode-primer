#include <vector>
#include <map>
using namespace std;

/*
    1. 二分答案
    2. 排序后的二分
    3. 平衡二叉树的二分
*/
class Solution{
public:
    int minAbsoluteDifference(vector<int>& nums,int x){
        /*
            4,2,3,4,5,x,7,2,3       x = 2
        */
        map<int,int> m;
        for(int num : nums){
            m[num]++;
        }
        int n = nums.size();
        int j = 0;
        int ans = INT_MAX;
        for(int i=0;i+x<n;i++){
            while(j<n && j - i < x){
                m[nums[j]]--;
                if(m[nums[j]] == 0){
                    m.erase(nums[j]);
                }
            }
            auto it = m.lower_bound(nums[i]);
            if(it != m.end()){
                ans = min(ans,it->first - nums[i]);
            }
            if(it != m.begin()){
                it--;
                ans = min(ans,nums[i] - it->first);
            }
        }
        return ans;
    }
};