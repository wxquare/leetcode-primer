#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:void solve(vector<vector<char>>&b){if(b.empty())return;int m=b.size(),n=b[0].size();function<void(int,int)>f=[&](int i,int j){if(i<0||j<0||i>=m||j>=n||b[i][j]!='O')return;b[i][j]='A';f(i+1,j);f(i-1,j);f(i,j+1);f(i,j-1);};for(int i=0;i<m;i++)f(i,0),f(i,n-1);for(int j=0;j<n;j++)f(0,j),f(m-1,j);for(auto&r:b)for(char&c:r)c=c=='A'?'O':'X';}};
