#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        int n = a.size();
        vector<int> o(n, -1);
        stack<int> s;
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && a[s.top()] < a[i % n]) o[s.top()] = a[i % n], s.pop();
            if (i < n) s.push(i);
        }
        return o;
    }
};
