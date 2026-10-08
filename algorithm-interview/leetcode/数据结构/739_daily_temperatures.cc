#include <vector>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        vector<int> r(a.size()), s;
        for (int i = 0; i < a.size(); i++) {
            while (!s.empty() && a[s.back()] < a[i]) r[s.back()] = i - s.back(), s.pop_back();
            s.push_back(i);
        }
        return r;
    }
};
