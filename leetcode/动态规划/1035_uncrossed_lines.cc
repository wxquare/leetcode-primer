#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int maxUncrossedLines(vector<int>&a,vector<int>&b){vector<int>d(b.size()+1);for(int x:a){int p=0;for(int j=1;j<=b.size();j++){int t=d[j];if(x==b[j-1])d[j]=p+1;else d[j]=max(d[j],d[j-1]);p=t;}}return d.back();} };
