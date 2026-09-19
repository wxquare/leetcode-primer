#include <vector>
using namespace std; class Solution{public:bool canMakeSquare(vector<vector<char>>&g){for(int i=0;i<2;i++)for(int j=0;j<2;j++){int c=(g[i][j]=='B')+(g[i+1][j]=='B')+(g[i][j+1]=='B')+(g[i+1][j+1]=='B');if(c!=2)return true;}return false;}};
