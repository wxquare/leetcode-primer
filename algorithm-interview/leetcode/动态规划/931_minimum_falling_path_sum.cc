#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        for (int i = 1; i < (int)a.size(); i++)
            for (int j = 0; j < (int)a[i].size(); j++) {
                int x = a[i - 1][j];
                if (j) x = min(x, a[i - 1][j - 1]);
                if (j + 1 < (int)a[i].size()) x = min(x, a[i - 1][j + 1]);
                a[i][j] += x;
            }
        return *min_element(a.back().begin(), a.back().end());
    }
};
