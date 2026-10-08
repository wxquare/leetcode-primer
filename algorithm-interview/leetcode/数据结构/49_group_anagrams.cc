#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        unordered_map<string, vector<string>> m;
        for (string x : a) {
            string k = x;
            sort(k.begin(), k.end());
            m[k].push_back(x);
        }
        vector<vector<string>> r;
        for (auto& p : m) r.push_back(p.second);
        return r;
    }
};
