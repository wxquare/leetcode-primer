#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        vector<int> s;
        int r = 0;
        for (int i = 0; i <= a.size(); i++) {
            int x = i < a.size() ? a[i] : 0;
            while (!s.empty() && a[s.back()] >= x) {
                int j = s.back();
                s.pop_back();
                int l = s.empty() ? -1 : s.back();
                r = max(r, a[j] * (i - l - 1));
            }
            s.push_back(i);
        }
        return r;
    }
};
