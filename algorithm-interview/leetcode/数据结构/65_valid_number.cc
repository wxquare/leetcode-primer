#include <string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
        int i = 0, n = s.size();
        while (i < n && s[i] == ' ') i++;
        bool dig = 0, dot = 0, exp = 0, ed = 1;
        for (; i < n; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') dig = ed = 1;
            else if (c == '.' && !dot && !exp) dot = 1;
            else if ((c == 'e' || c == 'E') && !exp && dig) {
                exp = 1;
                ed = 0;
            } else if ((c == '+' || c == '-') && (i == 0 || s[i - 1] == 'e' || s[i - 1] == 'E')) {
            } else if (c == ' ') break;
            else return false;
        }
        while (i < n && s[i] == ' ') i++;
        return i == n && dig && ed;
    }
};
