#include <string>
#include <algorithm>
using namespace std; class Solution{public:string finalString(string s){string r;for(char c:s)if(c=='i')reverse(r.begin(),r.end());else r+=c;return r;}};
