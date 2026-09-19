#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:int maxProduct(vector<int>&a){int hi=a[0],lo=a[0],r=a[0];for(int i=1;i<a.size();i++){if(a[i]<0)swap(hi,lo);hi=max(a[i],hi*a[i]);lo=min(a[i],lo*a[i]);r=max(r,hi);}return r;}};
