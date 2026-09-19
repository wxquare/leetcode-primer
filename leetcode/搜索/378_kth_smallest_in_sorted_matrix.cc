#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int> >& matrix, int k) {
        int lo = matrix[0][0], hi = matrix.back().back();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2, count = 0;
            for (size_t r = 0; r < matrix.size(); ++r)
                count += upper_bound(matrix[r].begin(), matrix[r].end(), mid) - matrix[r].begin();
            if (count < k) lo = mid + 1; else hi = mid;
        }
        return lo;
    }
};
