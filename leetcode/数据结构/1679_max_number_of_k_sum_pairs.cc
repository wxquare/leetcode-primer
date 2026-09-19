#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int maxOperations(vector<int>&a,int k){sort(a.begin(),a.end());int i=0,j=a.size()-1,r=0;while(i<j)if(a[i]+a[j]==k)i++,j--,r++;else if(a[i]+a[j]<k)i++;else j--;return r;}};
