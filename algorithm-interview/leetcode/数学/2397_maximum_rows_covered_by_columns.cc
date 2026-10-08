#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int columns = matrix[0].size(), ans = 0;
        for (int mask = 0; mask < (1 << columns); ++mask)
            if (__builtin_popcount((unsigned)mask) == numSelect) {
                int covered = 0;
                for (const auto& row : matrix) {
                    bool ok = true;
                    for (int j = 0; j < columns; ++j)
                        if (row[j] && !(mask >> j & 1)) {
                            ok = false;
                            break;
                        }
                    covered += ok;
                }
                ans = max(ans, covered);
            }
        return ans;
    }
};
