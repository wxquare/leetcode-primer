#include <vector>
using namespace std;
class Solution {
    int q(int a, int e) {
        int r = 1;
        for (; e; e >>= 1, a = (long long)a * a % 1337)
            if (e & 1) r = (long long)r * a % 1337;
        return r;
    }

public:
    int superPow(int a, vector<int>& b) {
        int r = 1;
        for (int d : b) r = (long long)q(r, 10) * q(a, d) % 1337;
        return r;
    }
};
