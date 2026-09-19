#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {vector<vector<int>> d={{1,0},{-1,0},{0,1},{0,-1}};bool f(vector<vector<char>>&b,string&s,int i,int j,int k){if(k==(int)s.size())return true;if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]!=s[k])return false;char c=b[i][j];b[i][j]='#';for(auto&x:d)if(f(b,s,i+x[0],j+x[1],k+1))return b[i][j]=c,true;b[i][j]=c;return false;}public:bool exist(vector<vector<char>>&b,string w){for(int i=0;i<b.size();i++)for(int j=0;j<b[0].size();j++)if(f(b,w,i,j,0))return true;return false;}};
