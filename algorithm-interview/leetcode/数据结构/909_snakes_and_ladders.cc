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
    int snakesAndLadders(vector<vector<int>>& b) {
        int n = b.size();
        queue<int> q;
        q.push(1);
        vector<int> d(n * n + 1, -1);
        d[1] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y = x + 1; y <= min(n * n, x + 6); y++) {
                int z = y - 1, i = n - 1 - z / n, j = z % n;
                if ((n - 1 - i) % 2) j = n - 1 - j;
                if (b[i][j] > 0) z = b[i][j];
                else z = y;
                if (d[z] < 0) d[z] = d[x] + 1, q.push(z);
            }
        }
        return d[n * n];
    }
};
