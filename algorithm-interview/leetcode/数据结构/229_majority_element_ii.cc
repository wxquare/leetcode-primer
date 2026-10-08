#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int x = 0, y = 1, cx = 0, cy = 0;
        for (int v : a) {
            if (v == x) cx++;
            else if (v == y) cy++;
            else if (!cx) x = v, cx = 1;
            else if (!cy) y = v, cy = 1;
            else cx--, cy--;
        }
        cx = cy = 0;
        for (int v : a) cx += v == x, cy += v == y;
        vector<int> r;
        if (cx > a.size() / 3) r.push_back(x);
        if (y != x && cy > a.size() / 3) r.push_back(y);
        return r;
    }
};
