#include <string>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& d) {
        unordered_set<string> x(d.begin(), d.end());
        vector<char> f(s.size() + 1);
        f[0] = 1;
        for (int i = 1; i <= s.size(); i++)
            for (int j = 0; j < i; j++)
                if (f[j] && x.count(s.substr(j, i - j))) {
                    f[i] = 1;
                    break;
                }
        return f.back();
    }
};
