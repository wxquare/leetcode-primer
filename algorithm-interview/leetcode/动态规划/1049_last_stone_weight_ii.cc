#include <vector>
using namespace std;
class Solution {
public:
    int lastStoneWeightII(vector<int>& a) {
        int s = 0;
        for (int x : a) s += x;
        vector<char> d(s / 2 + 1);
        d[0] = 1;
        for (int x : a)
            for (int j = s / 2; j >= x; j--) d[j] |= d[j - x];
        for (int j = s / 2; j >= 0; j--)
            if (d[j]) return s - 2 * j;
        return 0;
    }
};
