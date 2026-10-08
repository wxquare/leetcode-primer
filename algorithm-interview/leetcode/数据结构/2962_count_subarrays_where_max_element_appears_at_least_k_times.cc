#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        int mx = *max_element(a.begin(), a.end()), l = 0, c = 0;
        long long r = 0;
        for (int x : a) {
            c += x == mx;
            while (c >= k) c -= a[l++] == mx;
            r += l;
        }
        return r;
    }
};
