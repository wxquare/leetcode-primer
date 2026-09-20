#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& a, int t) {
        vector<int> d(t + 1, -1000000);
        d[0] = 0;
        for (int x : a)
            for (int j = t; j >= x; j--) d[j] = max(d[j], d[j - x] + 1);
        return d[t] < 0 ? -1 : d[t];
    }
};
