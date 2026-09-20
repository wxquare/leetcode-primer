#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& dead, string target) {
        unordered_set<string> b(dead.begin(), dead.end()), v;
        if (b.count("0000")) return -1;
        queue<string> q;
        q.push("0000");
        v.insert("0000");
        int d = 0;
        while (!q.empty()) {
            int z = q.size();
            while (z--) {
                string s = q.front();
                q.pop();
                if (s == target) return d;
                for (int i = 0; i < 4; i++)
                    for (int k = -1; k <= 1; k += 2) {
                        string t = s;
                        t[i] = (t[i] - '0' + k + 10) % 10 + '0';
                        if (!b.count(t) && v.insert(t).second) q.push(t);
                    }
            }
            d++;
        }
        return -1;
    }
};
