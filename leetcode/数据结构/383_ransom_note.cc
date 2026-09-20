#include <string>
using namespace std;
class Solution {
public:
    bool canConstruct(string a, string b) {
        int c[26] = {};
        for (char x : b) c[x - 'a']++;
        for (char x : a)
            if (!c[x - 'a']--) return false;
        return true;
    }
};
