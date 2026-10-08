#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> x, y, r;
        for (int i = 0; i + a.size() <= s.size(); i++)
            if (s.substr(i, a.size()) == a) x.push_back(i);
        for (int i = 0; i + b.size() <= s.size(); i++)
            if (s.substr(i, b.size()) == b) y.push_back(i);
        for (int i : x)
            for (int j : y)
                if (abs(i - j) <= k) {
                    r.push_back(i);
                    break;
                }
        return r;
    }
};
