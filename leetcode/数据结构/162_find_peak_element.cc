#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:int findPeakElement(vector<int>&a){int l=0,r=a.size()-1;while(l<r){int m=(l+r)/2;if(a[m]>a[m+1])r=m;else l=m+1;}return l;}};
