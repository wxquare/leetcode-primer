#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& w, vector<int>& g) {
        int n = w.size(), b = 0;
        vector<int> d(n, 1), p(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++)
                if (g[i] != g[j] && w[i].size() == w[j].size()) {
                    int c = 0;
                    for (int k = 0; k < w[i].size(); k++) c += w[i][k] != w[j][k];
                    if (c == 1 && d[j] + 1 > d[i]) d[i] = d[j] + 1, p[i] = j;
                }
            if (d[i] > d[b]) b = i;
        }
        vector<string> r;
        for (; b >= 0; b = p[b]) r.push_back(w[b]);
        reverse(r.begin(), r.end());
        return r;
    }
};
