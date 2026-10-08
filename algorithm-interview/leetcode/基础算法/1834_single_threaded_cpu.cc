#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<array<long long, 3>> a;
        for (int i = 0; i < tasks.size(); ++i) a.push_back({tasks[i][0], tasks[i][1], i});
        sort(a.begin(), a.end());
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            q;
        vector<int> ans;
        long long t = 0;
        int i = 0;
        while (i < a.size() || !q.empty()) {
            if (q.empty()) t = max(t, a[i][0]);
            while (i < a.size() && a[i][0] <= t) q.push({a[i][1], (int)a[i++][2]});
            pair<long long, int> cur = q.top();
            q.pop();
            t += cur.first;
            ans.push_back(cur.second);
        }
        return ans;
    }
};
