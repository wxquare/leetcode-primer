#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& a) {
        int s = 0;
        for (int x : a) s += x;
        if (s % 2) return false;
        vector<char> d(s / 2 + 1);
        d[0] = 1;
        for (int x : a)
            for (int j = s / 2; j >= x; j--) d[j] |= d[j - x];
        return d[s / 2];
    }
};
