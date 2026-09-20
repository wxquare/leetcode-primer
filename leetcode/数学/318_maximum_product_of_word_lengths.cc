#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& w) {
        vector<int> m;
        for (auto& s : w) {
            int x = 0;
            for (char c : s) x |= 1 << (c - 'a');
            m.push_back(x);
        }
        int r = 0;
        for (int i = 0; i < w.size(); ++i)
            for (int j = 0; j < i; ++j)
                if (!(m[i] & m[j])) r = max(r, (int)w[i].size() * (int)w[j].size());
        return r;
    }
};
