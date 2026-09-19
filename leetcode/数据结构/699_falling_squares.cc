#include <vector>
#include <algorithm>
using namespace std; class Solution{public:vector<int> fallingSquares(vector<vector<int>>&p){vector<int>h(p.size()),r;int mx=0;for(int i=0;i<p.size();i++){int l=p[i][0],rr=l+p[i][1];h[i]=p[i][1];for(int j=0;j<i;j++)if(max(l,p[j][0])<min(rr,p[j][0]+p[j][1]))h[i]=max(h[i],h[j]+p[i][1]);mx=max(mx,h[i]);r.push_back(mx);}return r;}};
