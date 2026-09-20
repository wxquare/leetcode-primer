#include <vector>
using namespace std;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int M = 1000000007;
        vector<vector<int>> d(n + 1, vector<int>(minProfit + 1));
        d[0][0] = 1;
        for (int z = 0; z < group.size(); z++)
            for (int g = n; g >= group[z]; g--)
                for (int p = minProfit; p >= 0; p--)
                    d[g][p] = (d[g][p] + d[g - group[z]][max(0, p - profit[z])]) % M;
        int r = 0;
        for (int g = 0; g <= n; g++) r = (r + d[g][minProfit]) % M;
        return r;
    }
};
