#include <vector>
#include <unordered_map>
using namespace std; class Solution{public:int threeSumMulti(vector<int>&a,int t){const long M=1000000007;unordered_map<int,long>m;long r=0;for(int x:a){for(auto&p:m)if(m.count(t-x-p.first))r=(r+p.second*m[t-x-p.first])%M;m[x]++;}return r%M;}};
