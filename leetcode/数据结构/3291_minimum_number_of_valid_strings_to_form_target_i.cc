#include <string>
#include <vector>
#include <algorithm>
using namespace std; class Solution{public:int minValidStrings(vector<string>&w,string t){int n=t.size();vector<int>d(n+1,1e9);d[0]=0;for(int i=0;i<n;i++)for(string&x:w)if(t.compare(i,x.size(),x)==0)d[i+x.size()]=min(d[i+x.size()],d[i]+1);return d[n]>=1e9?-1:d[n];}};
