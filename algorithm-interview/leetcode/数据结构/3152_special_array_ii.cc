#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
        vector<int> p(a.size());
        for (int i = 1; i < a.size(); i++) p[i] = p[i - 1] + ((a[i] % 2) == (a[i - 1] % 2));
        vector<bool> r;
        for (auto& x : q) r.push_back(p[x[0]] == p[x[1]]);
        return r;
    }
};
