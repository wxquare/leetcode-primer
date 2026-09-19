#include <vector>
using namespace std;
class Solution { public: int countOfPairs(vector<int>& nums) { const int M=1000000007; int m=nums[0];vector<int>d(m+1,1);for(int i=1;i<(int)nums.size();i++){vector<int>p(m+1);for(int j=0;j<=m;j++)p[j]=(p[j]+(j?p[j-1]:0))%M;vector<int>q(m+1);for(int a=0;a<=nums[i];a++){int lo=max(0,a-(nums[i-1]-m));q[a]=(p[m]- (lo?p[lo-1]:0)+M)%M;}d.swap(q);m=nums[i];}int r=0;for(int x:d)r=(r+x)%M;return r;} };
