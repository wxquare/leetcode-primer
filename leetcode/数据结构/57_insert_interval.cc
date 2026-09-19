#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:vector<vector<int>> insert(vector<vector<int>>&a,vector<int> n){vector<vector<int>>r;int i=0;while(i<a.size()&&a[i][1]<n[0])r.push_back(a[i++]);while(i<a.size()&&a[i][0]<=n[1])n={min(n[0],a[i][0]),max(n[1],a[i++][1])};r.push_back(n);while(i<a.size())r.push_back(a[i++]);return r;}};
