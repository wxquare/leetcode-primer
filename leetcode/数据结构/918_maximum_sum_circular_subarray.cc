#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int maxSubarraySumCircular(vector<int>&a){int sum=0,hi=a[0],lo=a[0],h=a[0],l=a[0];for(int i=1;i<a.size();i++)h=max(a[i],h+a[i]),hi=max(hi,h),l=min(a[i],l+a[i]),lo=min(lo,l);for(int x:a)sum+=x;return hi<0?hi:max(hi,sum-lo);}};
