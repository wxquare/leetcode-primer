#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        int n = nums.size(), ans = n;
        for (int i = 0; i < n; ++i) pos[nums[i]].push_back(i);
        for (unordered_map<int, vector<int>>::iterator it = pos.begin(); it != pos.end(); ++it) {
            vector<int>& a = it->second;
            int gap = 0;
            for (int i = 1; i < a.size(); ++i) gap = max(gap, a[i] - a[i - 1]);
            gap = max(gap, a[0] + n - a.back());
            ans = min(ans, gap / 2);
        }
        return ans;
    }
};
