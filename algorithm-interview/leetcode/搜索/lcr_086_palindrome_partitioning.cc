#include <string>
#include <vector>
using namespace std;

class Solution {
    vector<vector<string> > answer;
    vector<string> path;
    vector<vector<bool> > palindrome;

    void dfs(const string& s, int start) {
        if (start == static_cast<int>(s.size())) {
            answer.push_back(path);
            return;
        }
        for (int end = start; end < static_cast<int>(s.size()); ++end) {
            if (!palindrome[start][end]) continue;
            path.push_back(s.substr(start, end - start + 1));
            dfs(s, end + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string> > partition(string s) {
        int n = static_cast<int>(s.size());
        palindrome.assign(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                palindrome[i][j] = s[i] == s[j] &&
                    (j - i < 2 || palindrome[i + 1][j - 1]);
            }
        }
        answer.clear();
        path.clear();
        dfs(s, 0);
        return answer;
    }
};
