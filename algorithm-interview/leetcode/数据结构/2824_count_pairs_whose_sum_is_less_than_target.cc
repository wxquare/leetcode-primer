#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& a, int t) {
        sort(a.begin(), a.end());
        int i = 0, j = a.size() - 1, r = 0;
        while (i < j)
            if (a[i] + a[j] < t) r += j - i++;
            else j--;
        return r;
    }
};
