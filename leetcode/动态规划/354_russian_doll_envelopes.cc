#include <vector>
#include <algorithm>
using namespace std;
class Solution { public: int maxEnvelopes(vector<vector<int>>& e) { sort(e.begin(),e.end(),[](const vector<int>&a,const vector<int>&b){return a[0]!=b[0]?a[0]<b[0]:a[1]>b[1];}); vector<int>d;for(auto &x:e){vector<int>::iterator it=lower_bound(d.begin(),d.end(),x[1]);if(it==d.end())d.push_back(x[1]);else *it=x[1];}return d.size(); } };
