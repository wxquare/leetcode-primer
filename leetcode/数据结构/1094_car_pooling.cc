#include <vector>
using namespace std; class Solution{public:bool carPooling(vector<vector<int>>&t,int cap){int d[1001]={};for(auto&x:t)d[x[1]]+=x[0],d[x[2]]-=x[0];for(int i=0;i<1001;i++)if((cap-=d[i])<0)return false;return true;}};
