#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> a(num_people);
        for (int give = 1, i = 0; candies; give++, i = (i + 1) % num_people) {
            int x = min(candies, give);
            a[i] += x;
            candies -= x;
        }
        return a;
    }
};
