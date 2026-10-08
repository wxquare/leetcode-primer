#include <vector>
using namespace std;
class Solution {
public:
    int checkRecord(int n) {
        const int M = 1000000007;
        long long d[2][3] = {};
        d[0][0] = 1;
        for (int z = 0; z < n; z++) {
            long long t[2][3] = {};
            for (int a = 0; a < 2; a++)
                for (int l = 0; l < 3; l++) {
                    t[a][0] = (t[a][0] + d[a][l]) % M;
                    if (l < 2) t[a][l + 1] = (t[a][l + 1] + d[a][l]) % M;
                    if (a == 0) t[1][0] = (t[1][0] + d[a][l]) % M;
                }
            for (int a = 0; a < 2; a++)
                for (int l = 0; l < 3; l++) d[a][l] = t[a][l];
        }
        long long r = 0;
        for (int a = 0; a < 2; a++)
            for (int l = 0; l < 3; l++) r = (r + d[a][l]) % M;
        return r;
    }
};
