#include <vector>
using namespace std; class Solution{public:long long incremovableSubarrayCount(vector<int>&a){long long r=0;int n=a.size();for(int l=0;l<n;l++)for(int rr=l;rr<n;rr++){vector<int>b;for(int i=0;i<l;i++)b.push_back(a[i]);for(int i=rr+1;i<n;i++)b.push_back(a[i]);bool ok=1;for(int i=1;i<b.size();i++)ok&=b[i]>b[i-1];r+=ok;}return r;}};
