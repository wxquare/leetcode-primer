#include <string>
#include <vector>
#include <unordered_set>
using namespace std; class Solution{unordered_set<string>d;vector<string>f(string&s,int i){vector<string>r;if(i==s.size()){r.push_back("");return r;}for(int j=i+1;j<=s.size();j++)if(d.count(s.substr(i,j-i)))for(string x:f(s,j))r.push_back(s.substr(i,j-i)+(x.empty()?"":" "+x));return r;}public:vector<string> wordBreak(string s,vector<string>&w){d=unordered_set<string>(w.begin(),w.end());return f(s,0);}};
