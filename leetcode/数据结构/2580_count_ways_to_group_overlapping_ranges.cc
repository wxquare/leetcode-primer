#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int countWays(vector<vector<int>>&a){sort(a.begin(),a.end());long r=1;int e=-1;for(auto&x:a)if(x[0]>e)r=r*2%1000000007,e=x[1];else e=max(e,x[1]);return r;}};
