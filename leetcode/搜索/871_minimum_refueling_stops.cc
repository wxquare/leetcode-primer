#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        long long fuel = startFuel;
        int i = 0, ans = 0;
        while (fuel < target) {
            while (i < (int)stations.size() && stations[i][0] <= fuel) q.push(stations[i++][1]);
            if (q.empty()) return -1;
            fuel += q.top();
            q.pop();
            ++ans;
        }
        return ans;
    }
};
