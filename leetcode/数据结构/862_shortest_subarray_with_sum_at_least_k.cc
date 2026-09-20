#include <vector>
#include <deque>
#include <climits>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& a, int k) {
        int n = a.size(), r = n + 1;
        vector<long> s(n + 1);
        deque<int> q;
        for (int i = 0; i <= n; i++) {
            if (i) s[i] = s[i - 1] + a[i - 1];
            while (!q.empty() && s[i] - s[q.front()] >= k) r = min(r, i - q.front()), q.pop_front();
            while (!q.empty() && s[q.back()] >= s[i]) q.pop_back();
            q.push_back(i);
        }
        return r > n ? -1 : r;
    }
};
