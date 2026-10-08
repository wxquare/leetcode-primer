#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (char c : t)
            if (i < s.size() && s[i] == c) i++;
        return i == s.size();
    }
};
