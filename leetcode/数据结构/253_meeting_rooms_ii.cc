#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std; class Solution{public:int minMeetingRooms(vector<vector<int>>&a){vector<int>s,e;for(auto&x:a)s.push_back(x[0]),e.push_back(x[1]);sort(s.begin(),s.end());sort(e.begin(),e.end());int i=0,j=0,c=0;for(int x:s){if(x<e[j])c++;else j++;}return c;}};
