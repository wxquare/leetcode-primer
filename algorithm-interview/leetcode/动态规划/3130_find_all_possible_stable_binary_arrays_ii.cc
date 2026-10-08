#include <vector>
using namespace std;
class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int M = 1000000007;
        vector<vector<int>> a(zero + 1, vector<int>(one + 1)), b = a;
        for (int i = 1; i <= zero && i <= limit; i++) a[i][0] = 1;
        for (int j = 1; j <= one && j <= limit; j++) b[0][j] = 1;
        for (int i = 1; i <= zero; i++)
            for (int j = 1; j <= one; j++) {
                a[i][j] = (a[i - 1][j] + b[i - 1][j]) % M;
                if (i > limit) a[i][j] = (a[i][j] - b[i - limit - 1][j] + M) % M;
                b[i][j] = (a[i][j - 1] + b[i][j - 1]) % M;
                if (j > limit) b[i][j] = (b[i][j] - a[i][j - limit - 1] + M) % M;
            }
        return (a[zero][one] + b[zero][one]) % M;
    }
};
