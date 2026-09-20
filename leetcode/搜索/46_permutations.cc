#include <vector>
using namespace std;
class Solution {
    void dfs(int p, vector<int>& a, vector<vector<int>>& out) {
        if (p == (int)a.size()) {
            out.push_back(a);
            return;
        }
        for (int i = p; i < (int)a.size(); ++i) {
            swap(a[p], a[i]);
            dfs(p + 1, a, out);
            swap(a[p], a[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        dfs(0, nums, out);
        return out;
    }
};
