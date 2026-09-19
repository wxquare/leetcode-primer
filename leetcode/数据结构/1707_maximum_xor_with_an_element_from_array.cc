#include <vector>
#include <algorithm>
using namespace std; class Solution{public:vector<int> maximizeXor(vector<int>&a,vector<vector<int>>&q){vector<int>r;for(auto&z:q){int b=-1;for(int x:a)if(x<=z[1])b=max(b,x^z[0]);r.push_back(b);}return r;}};
