#include <string>
#include <set>
using namespace std;
class Solution {
public:
    bool isPathCrossing(string p) {
        set<pair<int, int>> s;
        s.insert({0, 0});
        int x = 0, y = 0;
        for (char c : p) {
            if (c == 'N') y++;
            if (c == 'S') y--;
            if (c == 'E') x++;
            if (c == 'W') x--;
            if (!s.insert({x, y}).second) return true;
        }
        return false;
    }
};
