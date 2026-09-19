#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int minIncrements(int n,vector<int>&c){int r=0;for(int i=n/2;i;i--){r+=abs(c[2*i-1]-c[2*i]);c[i-1]+=max(c[2*i-1],c[2*i]);}return r;}};
