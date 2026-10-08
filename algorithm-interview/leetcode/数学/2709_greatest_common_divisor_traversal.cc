#include <vector>
#include <numeric>
#include <unordered_map>
using namespace std;
class Solution {
    vector<int> p;
    int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) p[a] = b;
    }

public:
    bool canTraverseAllPairs(vector<int>& a) {
        int n = a.size();
        if (n == 1) return true;
        for (int x : a)
            if (x == 1) return false;
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        unordered_map<int, int> owner;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (int factor = 2; factor * factor <= x; ++factor)
                if (x % factor == 0) {
                    if (owner.count(factor)) unite(i, owner[factor]);
                    else owner[factor] = i;
                    while (x % factor == 0) x /= factor;
                }
            if (x > 1) {
                if (owner.count(x)) unite(i, owner[x]);
                else owner[x] = i;
            }
        }
        for (int i = 1; i < n; ++i)
            if (find(i) != find(0)) return false;
        return true;
    }
};
