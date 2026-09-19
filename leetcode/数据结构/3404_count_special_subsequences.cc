#include <vector>
using namespace std; class Solution{public:long long numberOfSubsequences(vector<int>&a){long long r=0;for(int p=0;p<a.size();p++)for(int q=p+1;q<a.size();q++)for(int r1=q+1;r1<a.size();r1++)for(int s=r1+1;s<a.size();s++)if((long long)a[p]*a[r1]==(long long)a[q]*a[s])r++;return r;}};
