#include <vector>
using namespace std; class Solution{public:vector<int> corpFlightBookings(vector<vector<int>>&b,int n){vector<int>d(n+1);for(auto&x:b)d[x[0]-1]+=x[2],d[x[1]]-=x[2];for(int i=1;i<n;i++)d[i]+=d[i-1];d.pop_back();return d;}};
