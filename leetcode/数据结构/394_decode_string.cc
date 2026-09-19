#include <string>
#include <vector>
using namespace std; class Solution{public:string decodeString(string s){vector<pair<string,int>>st;string r;int n=0;for(char c:s)if(isdigit(c))n=n*10+c-'0';else if(c=='[')st.push_back({r,n}),r="",n=0;else if(c==']'){auto p=st.back();st.pop_back();while(p.second--)r=p.first+r;}else r+=c;return r;}};
