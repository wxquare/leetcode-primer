#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](const vector<int>& c) {
            return (double)(c[0] + 1) / (c[1] + 1) - (double)c[0] / c[1];
        };
        priority_queue<pair<double, int>> q;
        for (int i = 0; i < classes.size(); ++i) q.push({gain(classes[i]), i});
        while (extraStudents--) {
            pair<double, int> cur = q.top();
            q.pop();
            int i = cur.second;
            ++classes[i][0];
            ++classes[i][1];
            q.push({gain(classes[i]), i});
        }
        double ans = 0;
        for (auto& c : classes) ans += (double)c[0] / c[1];
        return ans / classes.size();
    }
};
