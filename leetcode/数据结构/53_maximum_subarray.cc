#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:int maxSubArray(vector<int>&a){int b=a[0],s=a[0];for(int i=1;i<a.size();i++)s=max(a[i],s+a[i]),b=max(b,s);return b;}};
