#include <string>
#include <vector>
using namespace std;
class Solution { public: bool checkInclusion(string s1,string s2){if(s1.size()>s2.size())return false;vector<int>a(26),b(26);for(char c:s1)++a[c-'a'];for(int i=0;i<s2.size();++i){++b[s2[i]-'a'];if(i>=s1.size())--b[s2[i-s1.size()]-'a'];if(a==b)return true;}return false;} };
