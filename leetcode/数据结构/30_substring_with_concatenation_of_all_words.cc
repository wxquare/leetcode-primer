#include <string>
#include <vector>
#include <unordered_map>
using namespace std; class Solution{public:vector<int> findSubstring(string s,vector<string>&w){vector<int>r;if(w.empty())return r;int n=w[0].size(),m=w.size();unordered_map<string,int>need;for(auto&x:w)need[x]++;for(int o=0;o<n;o++){unordered_map<string,int>h;int l=o,c=0;for(int j=o;j+n<=s.size();j+=n){string x=s.substr(j,n);if(!need.count(x))h.clear(),c=0,l=j+n;else{h[x]++;c++;while(h[x]>need[x]){h[s.substr(l,n)]--;l+=n;c--;}if(c==m)r.push_back(l);}}}return r;}};
