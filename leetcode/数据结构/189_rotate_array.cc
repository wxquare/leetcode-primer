#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution { public: void rotate(vector<int>& a,int k){ if(a.empty()) return; k%=a.size(); reverse(a.begin(),a.end()); reverse(a.begin(),a.begin()+k); reverse(a.begin()+k,a.end()); } };
