#include <vector>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& a, int low, int high) {
        int z = 0;
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < i; j++)
                if ((a[i] ^ a[j]) >= low && (a[i] ^ a[j]) <= high) z++;
        return z;
    }
};
