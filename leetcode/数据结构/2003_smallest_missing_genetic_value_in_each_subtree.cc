#include <vector>
using namespace std; class Solution{public:vector<int> smallestMissingValueSubtree(vector<int>&p,vector<int>&v){vector<int>r(p.size(),1);for(int i=0;i<p.size();i++){int x=1;while(1){bool seen=0;for(int j=0;j<p.size();j++)if(v[j]==x)seen=1;if(!seen){r[i]=x;break;}x++;}}return r;}};
