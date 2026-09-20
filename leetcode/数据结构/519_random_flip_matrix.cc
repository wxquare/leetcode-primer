#include <unordered_map>
#include <vector>
#include <cstdlib>
using namespace std;
class Solution {
    int m, n, total;
    unordered_map<int, int> mp;

public:
    Solution(int m_, int n_) : m(m_), n(n_), total(m_ * n_) {}
    vector<int> flip() {
        int x = rand() % total--;
        int y = mp.count(x) ? mp[x] : x;
        mp[x] = mp.count(total) ? mp[total] : total;
        return {y / n, y % n};
    }
    void reset() {
        mp.clear();
        total = m * n;
    }
};
