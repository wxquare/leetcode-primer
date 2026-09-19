#include <vector>
#include <numeric>
#include <algorithm>
using namespace std; class Solution{public:int maxScore(vector<int>&a,int k){int n=a.size(),w=n-k,s=accumulate(a.begin(),a.begin()+w,0),m=s;for(int i=w;i<n;i++)s+=a[i]-a[i-w],m=min(m,s);return accumulate(a.begin(),a.end(),0)-m;}};
