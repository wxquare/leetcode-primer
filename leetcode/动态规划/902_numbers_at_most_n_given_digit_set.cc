#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        string s = to_string(N);
        int n = s.size(), r = 0;
        for (int i = 1; i < n; i++) {
            int p = 1;
            for (int j = 0; j < i; j++) p *= D.size();
            r += p;
        }
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (string& x : D)
                if (x[0] < s[i]) c++;
            int p = 1;
            for (int j = i + 1; j < n; j++) p *= D.size();
            r += c * p;
            bool ok = 0;
            for (string& x : D)
                if (x[0] == s[i]) ok = 1;
            if (!ok) return r;
        }
        return r + 1;
    }
};
