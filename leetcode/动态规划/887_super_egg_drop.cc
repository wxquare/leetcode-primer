#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int superEggDrop(int k,int n){vector<int>d(k+1);int m=0;while(d[k]<n){m++;for(int e=k;e>=1;e--)d[e]+=d[e-1]+1;}return m;} };
