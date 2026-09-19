#include <vector>
using namespace std;
class Solution { public: int countPrimes(int n) { vector<bool> p(n,true); int r=0; for(int i=2;i<n;++i) if(p[i]){++r; if((long long)i*i<n) for(int j=i*i;j<n;j+=i)p[j]=false;} return r; } };
