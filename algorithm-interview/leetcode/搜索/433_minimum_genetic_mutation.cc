#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> seen(bank.begin(), bank.end());
        if (!seen.count(end)) return -1;
        queue<string> q;
        q.push(start);
        int steps = 0;
        const string letters = "ACGT";
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string s = q.front();
                q.pop();
                if (s == end) return steps;
                for (int i = 0; i < (int)s.size(); ++i) {
                    char old = s[i];
                    for (char c : letters) {
                        s[i] = c;
                        if (seen.count(s)) {
                            seen.erase(s);
                            q.push(s);
                        }
                    }
                    s[i] = old;
                }
            }
            ++steps;
        }
        return -1;
    }
};
