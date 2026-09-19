#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution { public: int firstMissingPositive(vector<int>& a){int n=a.size();for(int i=0;i<n;i++)while(a[i]>0&&a[i]<=n&&a[a[i]-1]!=a[i])swap(a[i],a[a[i]-1]);for(int i=0;i<n;i++)if(a[i]!=i+1)return i+1;return n+1;}};
