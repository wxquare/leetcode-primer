#include <string>
#include <unordered_set>
using namespace std; class Solution{unordered_set<string>v;string r;int k;void go(string s){for(int i=0;i<k;i++){string t=s+char('0'+i);if(v.insert(t).second)go(t.substr(1)),r+=char('0'+i);}}public:string crackSafe(int n,int k_){k=k_;v.clear();r.clear();go(string(n-1,'0'));return r+string(n-1,'0');}};
