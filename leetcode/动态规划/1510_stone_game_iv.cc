#include <vector>
using namespace std; class Solution{public:bool winnerSquareGame(int n){vector<char>d(n+1);for(int i=1;i<=n;i++)for(int j=1;j*j<=i;j++)if(!d[i-j*j]){d[i]=1;break;}return d[n];}};
