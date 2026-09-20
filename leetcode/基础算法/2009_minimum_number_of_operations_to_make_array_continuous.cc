#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int original = nums.size();
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int n = nums.size(), j = 0, best = 0;
        for (int i = 0; i < n; ++i) {
            while (j < n && nums[j] - nums[i] < original) ++j;
            best = max(best, j - i);
        }
        return original - best;
    }
};
