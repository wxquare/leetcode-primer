#include <vector>
#include <algorithm>
using namespace std;
class Solution { public: int maxSumAfterPartitioning(vector<int>& arr,int k) { int n=arr.size(); vector<int> d(n+1); for(int i=1;i<=n;i++){int mx=0;for(int j=1;j<=k&&j<=i;j++){mx=max(mx,arr[i-j]);d[i]=max(d[i],d[i-j]+mx*j);}} return d[n]; } };
