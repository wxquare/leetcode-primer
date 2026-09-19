#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution { public:int findMaxForm(vector<string>&strs,int m,int n){vector<vector<int>>d(m+1,vector<int>(n+1));for(string&s:strs){int z=0;for(char c:s)z+=c=='0';int o=s.size()-z;for(int i=m;i>=z;i--)for(int j=n;j>=o;j--)d[i][j]=max(d[i][j],d[i-z][j-o]+1);}return d[m][n];} };
