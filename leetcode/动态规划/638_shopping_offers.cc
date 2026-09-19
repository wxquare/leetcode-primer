#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution { map<vector<int>,int>memo; public:int shoppingOffers(vector<int>&p,vector<vector<int>>&sp,vector<int>&needs){if(memo.count(needs))return memo[needs];int r=0;for(int i=0;i<needs.size();i++)r+=needs[i]*p[i];for(auto&o:sp){bool ok=1;vector<int>q=needs;for(int i=0;i<needs.size();i++)if((q[i]-=o[i])<0)ok=0;if(ok)r=min(r,o.back()+shoppingOffers(p,sp,q));}return memo[needs]=r;} };
