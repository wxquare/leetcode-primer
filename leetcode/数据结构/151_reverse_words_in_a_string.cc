#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution { public: string reverseWords(string s){ stringstream in(s); vector<string> v; string w; while(in>>w)v.push_back(w); reverse(v.begin(),v.end()); string r; for(string x:v){if(!r.empty())r+=' ';r+=x;} return r;} };
