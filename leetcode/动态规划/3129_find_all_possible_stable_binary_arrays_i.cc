#include <vector>
using namespace std;
class Solution {public:int numberOfStableArrays(int z,int o,int lim){const int M=1000000007;vector<vector<vector<int>>>d(z+1,vector<vector<int>>(o+1,vector<int>(2)));for(int i=0;i<=z;i++)for(int j=0;j<=o;j++){if(i==0&&j==0)continue;if(i)for(int k=1;k<=lim&&i>=k;k++)d[i][j][0]=(d[i][j][0]+(i-k?d[i-k][j][1]:1))%M;if(j)for(int k=1;k<=lim&&j>=k;k++)d[i][j][1]=(d[i][j][1]+(j-k?d[i][j-k][0]:1))%M;}return (d[z][o][0]+d[z][o][1])%M;}};
