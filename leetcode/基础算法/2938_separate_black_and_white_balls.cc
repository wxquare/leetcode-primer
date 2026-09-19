#include <string>
using namespace std;
class Solution { public: long long minimumSteps(string s) { long long white=0,ans=0; for(char c:s) if(c=='0') ans+=white; else ++white; return ans; } };
