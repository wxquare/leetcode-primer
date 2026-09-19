#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int maxValueOfCoins(vector<vector<int>>&p,int k){vector<int>d(k+1);for(auto&v:p){vector<int>q=d,s(v.size()+1);for(int i=1;i<=v.size();i++)s[i]=s[i-1]+v[i-1];for(int x=1;x<=k&&x<=s.size()-1;x++)for(int j=x;j<=k;j++)q[j]=max(q[j],d[j-x]+s[x]);d.swap(q);}return d[k];} };
