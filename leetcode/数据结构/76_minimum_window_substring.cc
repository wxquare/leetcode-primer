#include <string>
#include <vector>
using namespace std; class Solution{public:string minWindow(string s,string t){vector<int>c(128);for(char x:t)c[x]++;int need=t.size(),l=0,b=0,len=1e9;for(int r=0;r<s.size();r++){if(c[s[r]]-->0)need--;while(!need){if(r-l+1<len)len=r-l+1,b=l;if(++c[s[l++]]>0)need++;} }return len==1e9?"":s.substr(b,len);}};
