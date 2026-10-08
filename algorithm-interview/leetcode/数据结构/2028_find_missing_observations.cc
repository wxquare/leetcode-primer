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
    vector<int> missingRolls(vector<int>& r, int mean, int n) {
        int s = mean * (n + r.size());
        for (int x : r) s -= x;
        if (s < n || s > 6 * n) return {};
        vector<int> a(n, s / n);
        for (int& i : a) i += s % n > 0, s % n--;
        return a;
    }
};
