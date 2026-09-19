#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:vector<int> findPeakGrid(vector<vector<int>>&a){int l=0,r=a.size()-1;while(l<r){int m=(l+r)/2,j=max_element(a[m].begin(),a[m].end())-a[m].begin();if(a[m][j]<a[m+1][j])l=m+1;else r=m;}int j=max_element(a[l].begin(),a[l].end())-a[l].begin();return{l,j};}};
