#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<string> r;
    void f(string& s, int n) {
        if (s.size() == n) {
            r.push_back(s);
            return;
        }
        s += '1';
        f(s, n - 1);
        s.pop_back();
        if (s.empty() || s.back() != '0') {
            s += '0';
            f(s, n - 1);
            s.pop_back();
        }
    }

public:
    vector<string> validStrings(int n) {
        string s;
        f(s, n);
        return r;
    }
};
