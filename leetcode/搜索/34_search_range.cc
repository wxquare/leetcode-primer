#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>::iterator first = lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) return vector<int>(2, -1);
        vector<int>::iterator last = upper_bound(nums.begin(), nums.end(), target);
        return vector<int>{static_cast<int>(first - nums.begin()),
                           static_cast<int>(last - nums.begin() - 1)};
    }
};
