#include <string>
using namespace std; class Solution{public:int countSubstrings(string s){int r=0;for(int c=0;c<s.size();c++)for(int l=c,h=c;l>=0&&h<s.size()&&s[l--]==s[h++];)r++;for(int c=0;c+1<s.size();c++)for(int l=c,h=c+1;l>=0&&h<s.size()&&s[l--]==s[h++];)r++;return r;}};
