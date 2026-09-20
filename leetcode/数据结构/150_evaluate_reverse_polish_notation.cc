#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& a) {
        vector<int> s;
        for (string x : a)
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                int b = s.back();
                s.pop_back();
                int c = s.back();
                s.pop_back();
                s.push_back(x == "+" ? c + b : x == "-" ? c - b : x == "*" ? c * b : c / b);
            } else s.push_back(atoi(x.c_str()));
        return s.back();
    }
};
