#include <vector>
using namespace std;
class Solution {
    int power(int a, int e, int mod) {
        long long r = 1 % mod, base = a % mod;
        while (e) {
            if (e & 1) r = r * base % mod;
            base = base * base % mod;
            e >>= 1;
        }
        return r;
    }

public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < (int)variables.size(); ++i) {
            int first = power(variables[i][0], variables[i][1], 10);
            if (power(first, variables[i][2], variables[i][3]) == target) ans.push_back(i);
        }
        return ans;
    }
};
