#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size(), B = 61;
        vector<vector<int>> up(B, vector<int>(n));
        vector<vector<long long>> sm(B, vector<long long>(n));
        for (int i = 0; i < n; i++) up[0][i] = receiver[i], sm[0][i] = receiver[i];
        for (int j = 1; j < B; j++)
            for (int i = 0; i < n; i++)
                up[j][i] = up[j - 1][up[j - 1][i]],
                sm[j][i] = sm[j - 1][i] + sm[j - 1][up[j - 1][i]];
        long long r = 0;
        for (int s = 0; s < n; s++) {
            long long v = s;
            int u = s;
            for (int j = 0; k; j++, k >>= 1)
                if (k & 1) v += sm[j][u], u = up[j][u];
            r = max(r, v);
        }
        return r;
    }
};
