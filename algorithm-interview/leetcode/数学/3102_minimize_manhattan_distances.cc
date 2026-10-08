#include <algorithm>
#include <climits>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        multiset<int> sum, diff;
        for (const auto& p : points) {
            sum.insert(p[0] + p[1]);
            diff.insert(p[0] - p[1]);
        }
        int ans = INT_MAX;
        for (const auto& p : points) {
            int a = p[0] + p[1], b = p[0] - p[1];
            sum.erase(sum.find(a));
            diff.erase(diff.find(b));
            ans = min(ans, max(*sum.rbegin() - *sum.begin(), *diff.rbegin() - *diff.begin()));
            sum.insert(a);
            diff.insert(b);
        }
        return ans;
    }
};
