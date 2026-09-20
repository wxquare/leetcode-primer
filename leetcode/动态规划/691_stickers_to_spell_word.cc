#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minStickers(vector<string>& st, string target) {
        int n = target.size(), N = 1 << n, inf = 1000000000;
        vector<int> d(N, inf);
        d[0] = 0;
        for (int m = 0; m < N; m++)
            if (d[m] < inf)
                for (string& s : st) {
                    int q = m;
                    for (char c : s)
                        for (int i = 0; i < n; i++)
                            if (!(q >> i & 1) && target[i] == c) {
                                q |= 1 << i;
                                break;
                            }
                    d[q] = min(d[q], d[m] + 1);
                }
        return d[N - 1] == inf ? -1 : d[N - 1];
    }
};
