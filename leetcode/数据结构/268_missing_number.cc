#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& a) {
        int x = a.size();
        for (int i = 0; i < a.size(); i++) x ^= i ^ a[i];
        return x;
    }
};
