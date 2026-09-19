#include <vector>
#include <unordered_map>
using namespace std; class Solution{public:long long beautifulSubarrays(vector<int>&a){unordered_map<int,long long>m{{0,1}};long long r=0;int x=0;for(int v:a)x^=v,r+=m[x]++,void();return r;}};
