#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = (n + 1) / 2, c = 0;
        while (i < n / 2 && j < n) {
            if (2LL * nums[i] <= nums[j]) ++i, ++j, c += 2;
            else ++j;
        }
        return c;
    }
};
