#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        vector<int> r;
        for (auto& x : q) {
            int a = x[0], b = x[1];
            if (a > b) swap(a, b);
            if (a == b || h[a] < h[b]) r.push_back(b);
            else {
                int z = -1;
                for (int i = b + 1; i < h.size(); i++)
                    if (h[i] > h[a]) {
                        z = i;
                        break;
                    }
                r.push_back(z);
            }
        }
        return r;
    }
};
