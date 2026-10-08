#include <vector>
using namespace std;
class Solution {
    void go(vector<vector<int>>& r, vector<int>& v, int x) {
        if (v[x]) return;
        v[x] = 1;
        for (int y : r[x]) go(r, v, y);
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        vector<int> v(r.size());
        go(r, v, 0);
        for (int x : v)
            if (!x) return false;
        return true;
    }
};
