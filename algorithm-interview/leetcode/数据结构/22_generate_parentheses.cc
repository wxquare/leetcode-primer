#include <vector>
#include <string>
using namespace std;
class Solution {
    vector<string> r;
    void f(string& s, int a, int b) {
        if (!a && !b) {
            r.push_back(s);
            return;
        }
        if (a) {
            s += '(';
            f(s, a - 1, b);
            s.pop_back();
        }
        if (b > a) {
            s += ')';
            f(s, a, b - 1);
            s.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        string s;
        f(s, n, n);
        return r;
    }
};
