#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:int minSubArrayLen(int t,vector<int>&a){int l=0,s=0,r=INT_MAX;for(int i=0;i<a.size();i++){s+=a[i];while(s>=t)r=min(r,i-l+1),s-=a[l++];}return r==INT_MAX?0:r;}};
