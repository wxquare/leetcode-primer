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
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        int m = a.size(), n = a[0].size();
        for (int s = 0; s < m + n - 1; s++) {
            vector<int> v;
            for (int i = max(0, s - n + 1); i <= min(m - 1, s); i++) v.push_back(a[i][s - i]);
            sort(v.rbegin(), v.rend());
            int k = 0;
            for (int i = max(0, s - n + 1); i <= min(m - 1, s); i++) a[i][s - i] = v[k++];
        }
        return a;
    }
};
