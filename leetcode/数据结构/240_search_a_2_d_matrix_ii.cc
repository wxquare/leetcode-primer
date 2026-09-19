#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:bool searchMatrix(vector<vector<int>>&a,int t){if(a.empty())return false;int i=0,j=a[0].size()-1;while(i<a.size()&&j>=0){if(a[i][j]==t)return true;if(a[i][j]>t)j--;else i++;}return false;}};
