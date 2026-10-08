#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, i = 0, r = nums.size() - 1;
        while (i <= r) {
            if (nums[i] == 0) swap(nums[l++], nums[i++]);
            else if (nums[i] == 2) swap(nums[i], nums[r--]);
            else ++i;
        }
    }
};
