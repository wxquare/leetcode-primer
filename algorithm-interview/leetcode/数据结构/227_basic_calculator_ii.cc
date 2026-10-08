#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int calculate(string s) {
        vector<int> v;
        long n = 0;
        char op = '+';
        for (int i = 0; i <= s.size(); i++) {
            char c = i < s.size() ? s[i] : '+';
            if (c >= '0' && c <= '9') n = n * 10 + c - '0';
            else if (c != ' ') {
                if (op == '+') v.push_back(n);
                else if (op == '-') v.push_back(-n);
                else if (op == '*') v.back() *= n;
                else v.back() /= n;
                op = c;
                n = 0;
            }
        }
        int r = 0;
        for (int x : v) r += x;
        return r;
    }
};
