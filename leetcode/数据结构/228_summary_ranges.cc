#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:vector<string> summaryRanges(vector<int>&a){vector<string>r;for(int i=0;i<a.size();){int j=i;while(j+1<a.size()&&a[j+1]==a[j]+1)j++;r.push_back(to_string(a[i])+(i==j?"":"->"+to_string(a[j])));i=j+1;}return r;}};
