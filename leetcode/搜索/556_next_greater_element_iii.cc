#include <algorithm>
#include <string>
using namespace std;
class Solution { public:int nextGreaterElement(int n){string s=to_string(n);if(!next_permutation(s.begin(),s.end()))return -1;long long x=stoll(s);return x>2147483647?-1:(int)x;} };
