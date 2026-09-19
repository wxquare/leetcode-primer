#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{int n,c;vector<int>a,b,d;void f(int i){if(i==n){c++;return;}for(int j=0;j<n;j++)if(!a[j]&&!b[i+j]&&!d[i-j+n])a[j]=b[i+j]=d[i-j+n]=1,f(i+1),a[j]=b[i+j]=d[i-j+n]=0;}public:int totalNQueens(int N){n=N;c=0;a.assign(n,0);b.assign(2*n,0);d.assign(2*n,0);f(0);return c;}};
