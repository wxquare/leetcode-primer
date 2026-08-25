#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(
        string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary(wordList.begin(), wordList.end());
        if (!dictionary.count(endWord)) {
            return {};
        }

        unordered_map<string, vector<string>> parents;
        vector<string> level = {beginWord};
        dictionary.erase(beginWord);
        bool found = false;

        while (!level.empty() && !found) {
            unordered_set<string> nextLevel;

            for (const string& word : level) {
                string candidate = word;
                for (int i = 0; i < static_cast<int>(candidate.size()); ++i) {
                    const char original = candidate[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == original) {
                            continue;
                        }
                        candidate[i] = c;
                        if (!dictionary.count(candidate)) {
                            continue;
                        }
                        parents[candidate].push_back(word);
                        nextLevel.insert(candidate);
                        if (candidate == endWord) {
                            found = true;
                        }
                    }
                    candidate[i] = original;
                }
            }

            for (const string& word : nextLevel) {
                dictionary.erase(word);
            }
            level.assign(nextLevel.begin(), nextLevel.end());
        }

        vector<vector<string>> result;
        if (!found) {
            return result;
        }

        vector<string> path = {endWord};
        auto dfs = [&](auto&& self, const string& word) -> void {
            if (word == beginWord) {
                result.emplace_back(path.rbegin(), path.rend());
                return;
            }

            for (const string& parent : parents.at(word)) {
                path.push_back(parent);
                self(self, parent);
                path.pop_back();
            }
        };
        dfs(dfs, endWord);
        return result;
    }
};
