#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:int eraseOverlapIntervals(vector<vector<int>>&a){sort(a.begin(),a.end(),[](const vector<int>&x,const vector<int>&y){return x[1]<y[1];});int e=INT_MIN,c=0;for(auto&x:a)if(x[0]<e)c++;else e=x[1];return c;}};
