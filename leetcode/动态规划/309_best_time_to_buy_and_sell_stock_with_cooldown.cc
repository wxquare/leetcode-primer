#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int h = -1000000000, s = 0, c = 0;
        for (int x : p) {
            int nh = max(h, c - x), nc = max(c, s), ns = h + x;
            h = nh;
            c = nc;
            s = ns;
        }
        return max(c, s);
    }
};
