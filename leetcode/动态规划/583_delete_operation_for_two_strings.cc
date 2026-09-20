#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string a, string b) {
        vector<int> d(b.size() + 1);
        for (int j = 1; j <= b.size(); j++) d[j] = j;
        for (int i = 1; i <= a.size(); i++) {
            int p = d[0];
            d[0] = i;
            for (int j = 1; j <= b.size(); j++) {
                int t = d[j];
                d[j] = a[i - 1] == b[j - 1] ? p : min(d[j] + 1, d[j - 1] + 1);
                p = t;
            }
        }
        return d[b.size()];
    }
};
