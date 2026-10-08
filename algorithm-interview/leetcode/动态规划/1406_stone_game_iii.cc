#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string stoneGameIII(vector<int>& a) {
        int n = a.size();
        vector<int> d(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            d[i] = -1000000000;
            int s = 0;
            for (int k = 0; k < 3 && i + k < n; k++)
                s += a[i + k], d[i] = max(d[i], s - d[i + k + 1]);
        }
        return d[0] > 0 ? "Alice" : d[0] < 0 ? "Bob" : "Tie";
    }
};
