#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    string simplifyPath(string p) {
        vector<string> v;
        stringstream s(p);
        string x;
        while (getline(s, x, '/'))
            if (x == ".." && !v.empty()) v.pop_back();
            else if (!x.empty() && x != ".") v.push_back(x);
        string r;
        for (auto& z : v) r += "/" + z;
        return r.empty() ? "/" : r;
    }
};
