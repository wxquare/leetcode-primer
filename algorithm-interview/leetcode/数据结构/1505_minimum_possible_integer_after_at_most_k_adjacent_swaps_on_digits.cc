#include <string>
using namespace std;
class Solution {
public:
    string minInteger(string s, int k) {
        for (int i = 0; i < s.size() && k; i++) {
            int p = i;
            for (int j = i + 1; j < s.size() && j - i <= k; j++)
                if (s[j] < s[p]) p = j;
            if (p != i) {
                char c = s[p];
                for (int j = p; j > i; j--) s[j] = s[j - 1];
                s[i] = c;
                k -= p - i;
            }
        }
        return s;
    }
};
