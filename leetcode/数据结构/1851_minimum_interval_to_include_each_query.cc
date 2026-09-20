#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& in, vector<int>& q) {
        sort(in.begin(), in.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < q.size(); i++) v.push_back({q[i], i});
        sort(v.begin(), v.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> h;
        vector<int> r(q.size());
        int j = 0;
        for (auto [x, id] : v) {
            while (j < in.size() && in[j][0] <= x) h.push({in[j][1] - in[j][0] + 1, in[j][1]}), j++;
            while (!h.empty() && h.top().second < x) h.pop();
            r[id] = h.empty() ? -1 : h.top().first;
        }
        return r;
    }
};
