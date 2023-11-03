#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution{
public:
    vector<int> maxSlidingWindow(vector<int>& nums,int k){
        /*
            3,2,4,5,1,3,7,2
            单调递减对列
        */
        deque<int> q;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(!q.empty() && nums[i] >= nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
            if(i < k - 1) continue;

            while(i - q.front() + 1 > k){
                q.pop_front();
            }
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {3,2,4,5,1,3,7,2};
    vector<int> ans = Solution().maxSlidingWindow(nums,3);

    for(int i=0;i<ans.size();i++){
        std::cout << ans[i] << std::endl;
    }
}