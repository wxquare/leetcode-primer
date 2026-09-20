#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<unsigned long long> d(t.size() + 1);
        d[0] = 1;
        for (char c : s)
            for (int j = t.size() - 1; j >= 0; j--)
                if (c == t[j]) d[j + 1] += d[j];
        return d[t.size()];
    }
};
