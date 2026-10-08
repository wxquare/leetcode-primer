#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> free;
        for (int i = 0; i < n; ++i) free.push(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            busy;
        vector<int> cnt(n);
        for (auto& m : meetings) {
            long long s = m[0], e = m[1];
            while (!busy.empty() && busy.top().first <= s) {
                free.push(busy.top().second);
                busy.pop();
            }
            if (free.empty()) {
                pair<long long, int> cur = busy.top();
                busy.pop();
                s = cur.first;
                e = s + m[1] - m[0];
                free.push(cur.second);
            }
            int id = free.top();
            free.pop();
            ++cnt[id];
            busy.push({e, id});
        }
        return max_element(cnt.begin(), cnt.end()) - cnt.begin();
    }
};
