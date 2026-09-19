#include <unordered_set>
using namespace std;
class Solution { int next(int n){int s=0;while(n){int d=n%10;s+=d*d;n/=10;}return s;} public: bool isHappy(int n){unordered_set<int> seen;while(n!=1&&seen.insert(n).second)n=next(n);return n==1;} };
