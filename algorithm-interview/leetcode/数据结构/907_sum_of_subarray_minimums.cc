#include <vector>
using namespace std;
class Solution {
public:
    int sumSubarrayMins(vector<int>& a) {
        const long M = 1000000007;
        long r = 0;
        vector<int> s;
        for (int i = 0; i <= a.size(); i++) {
            int x = i < a.size() ? a[i] : 0;
            while (!s.empty() && (i == a.size() || a[s.back()] >= x)) {
                int j = s.back();
                s.pop_back();
                int l = s.empty() ? -1 : s.back();
                r = (r + (long)a[j] * (j - l) * (i - j)) % M;
            }
            s.push_back(i);
        }
        return r;
    }
};
