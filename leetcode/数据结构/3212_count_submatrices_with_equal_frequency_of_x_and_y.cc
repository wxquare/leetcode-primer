#include <vector>
using namespace std; class Solution{public:int numberOfSubmatrices(vector<vector<char>>&g){int m=g.size(),n=g[0].size(),r=0;for(int i=0;i<m;i++)for(int j=0;j<n;j++){int x=0,y=0;for(int a=0;a<=i;a++)for(int b=0;b<=j;b++)x+=g[a][b]=='X',y+=g[a][b]=='Y';if(x==y&&x)r++;}return r;}};
