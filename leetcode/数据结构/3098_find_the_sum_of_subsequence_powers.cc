#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int sumOfPowers(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        long long r = 0;
        for (int i = 0; i + k <= a.size(); i++) {
            int d = 1e9;
            for (int j = i + 1; j < i + k; j++) d = min(d, a[j] - a[j - 1]);
            r = (r + d) % 1000000007;
        }
        return r;
    }
};
