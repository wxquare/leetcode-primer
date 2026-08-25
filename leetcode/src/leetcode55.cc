#include <vector>
#include <iostream>
using namespace std;

class Solution{
public:
    bool canJump(vector<int>& nums){
        int mx = 0;
        for(int i=0;i<nums.size();i++){
            if(mx < i) return false;
            mx = max(mx,nums[i]+i);
        }
        return true;
    }
};

int main(){
    vector<int> nums = {3,2,1,1,4};
    std::cout << Solution().canJump(nums) << std::endl;
}