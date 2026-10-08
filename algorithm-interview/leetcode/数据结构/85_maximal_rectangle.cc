#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& a) {
        if (a.empty()) return 0;
        int n = a[0].size(), r = 0;
        vector<int> h(n);
        for (auto& x : a) {
            for (int j = 0; j < n; j++) h[j] = x[j] == '1' ? h[j] + 1 : 0;
            vector<int> s;
            for (int i = 0; i <= n; i++) {
                int v = i < n ? h[i] : 0;
                while (!s.empty() && h[s.back()] >= v) {
                    int k = s.back();
                    s.pop_back();
                    int l = s.empty() ? -1 : s.back();
                    r = max(r, h[k] * (i - l - 1));
                }
                s.push_back(i);
            }
        }
        return r;
    }
};
