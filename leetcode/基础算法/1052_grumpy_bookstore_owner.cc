#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0, gain = 0, best = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (!grumpy[i]) base += customers[i];
            else gain += customers[i];
            if (i >= minutes && grumpy[i - minutes]) gain -= customers[i - minutes];
            best = max(best, gain);
        }
        return base + best;
    }
};
