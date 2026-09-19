#include <string>
#include <vector>
using namespace std;
class Solution {public:int countSpecialNumbers(int n){string s=to_string(n);int z=s.size(),r=0;for(int i=1;i<z;i++){int p=9;for(int j=1;j<i;j++)p*=10-j;r+=p;}vector<int>d(10);for(int i=0;i<z;i++){int x=s[i]-'0',c=0;for(int q=0;q<x;q++)if(!d[q]&&(i||q))c++;int p=1;for(int j=i+1;j<z;j++)p*=10-i-1-j+i+1;int rem=10-i-1;for(int j=0;j<z-i-1;j++)p*=9-j; r+=c*p;if(d[x])return r;d[x]=1;}return r+1;}};
