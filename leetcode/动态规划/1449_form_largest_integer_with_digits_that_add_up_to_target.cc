#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<string> d(target + 1, "#");
        d[0] = "";
        for (int t = 1; t <= target; t++)
            for (int x = 0; x < 9; x++)
                if (t >= cost[x] && d[t - cost[x]] != "#") {
                    string q = char('1' + x) + d[t - cost[x]];
                    if (d[t] == "#" || q.size() > d[t].size() ||
                        (q.size() == d[t].size() && q > d[t]))
                        d[t] = q;
                }
        return d[target] == "#" ? "0" : d[target];
    }
};
