#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        unordered_set<int> s(passengers.begin(), passengers.end());
        int p = 0, last = 0;
        for (int b : buses) {
            int cnt = 0;
            while (p < passengers.size() && passengers[p] <= b && cnt < capacity) {
                last = passengers[p++];
                ++cnt;
            }
            if (b == buses.back()) {
                int t = cnt < capacity ? b : last - 1;
                while (s.count(t)) --t;
                return t;
            }
        }
        return 0;
    }
};
