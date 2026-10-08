#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        long long sum = 0, ans = 1LL << 62;
        for (int x : beans) sum += x;
        for (int i = 0; i < beans.size(); ++i)
            ans = min(ans, sum - 1LL * beans[i] * (static_cast<long long>(beans.size()) - i));
        return ans;
    }
};
