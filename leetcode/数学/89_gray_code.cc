#include <vector>
using namespace std;
class Solution { public: vector<int> grayCode(int n) { vector<int> r(1,0); for(int b=0;b<n;++b){int s=r.size(); for(int i=s-1;i>=0;--i) r.push_back(r[i]|(1<<b));} return r; } };
