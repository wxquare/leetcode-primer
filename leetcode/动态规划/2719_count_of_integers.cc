#include <string>
#include <vector>
using namespace std;
class Solution {long long f(string s,int lo,int hi){const int M=1000000007;int n=s.size();vector<vector<vector<int>>>d(n+1,vector<vector<int>>(hi+1,vector<int>(2)));d[0][0][1]=1;for(int i=0;i<n;i++)for(int q=0;q<=hi;q++)for(int t=0;t<2;t++)if(d[i][q][t])for(int x=0;x<=9;x++){if(q+x>hi)break;int nt=t&&x==s[i]-'0';if(t&&x>s[i]-'0')continue;d[i+1][q+x][nt]=(d[i+1][q+x][nt]+d[i][q][t])%M;}long long r=0;for(int q=lo;q<=hi;q++)for(int t=0;t<2;t++)r=(r+d[n][q][t])%M;return r;}public:int count(string num1,string num2,int min_sum,int max_sum){const int M=1000000007;long long a=f(num2,min_sum,max_sum),b=f(to_string(stoll(num1)-1),min_sum,max_sum);return (a-b+M)%M;}};
