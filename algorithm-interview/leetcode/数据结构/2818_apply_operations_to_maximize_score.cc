#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& a, int k) {
        sort(a.rbegin(), a.rend());
        long long r = 1;
        for (int i = 0; i < k; i++) r = r * a[i] % 1000000007;
        return r;
    }
};
