#include <vector>
#include <algorithm>
using namespace std;
class Solution { public: int findLongestChain(vector<vector<int>>& p){sort(p.begin(),p.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});int r=0,e=-1000000000;for(auto&x:p)if(x[0]>e)r++,e=x[1];return r;} };
