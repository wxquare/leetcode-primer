#include <vector>
using namespace std;
class Solution { public: int integerBreak(int n){vector<int>d(n+1);d[1]=1;for(int i=2;i<=n;++i)for(int j=1;j<i;++j)d[i]=max(d[i],j*max(i-j,d[i-j]));return d[n];} };
