#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n = a.size();
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n; j++) {
                int x = 1000000000;
                for (int k = 0; k < n; k++)
                    if (k != j) x = min(x, a[i - 1][k]);
                a[i][j] += x;
            }
        return *min_element(a.back().begin(), a.back().end());
    }
};
