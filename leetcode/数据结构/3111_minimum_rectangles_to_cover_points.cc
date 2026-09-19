#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int minRectanglesToCoverPoints(vector<vector<int>>&p,int w){sort(p.begin(),p.end());int r=0,e=-1;for(auto&x:p)if(x[0]>e)r++,e=x[0]+w;return r;}};
