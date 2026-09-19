#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:vector<vector<int>> threeSum(vector<int>&a){sort(a.begin(),a.end());vector<vector<int>>r;for(int i=0;i<a.size();i++){if(i&&a[i]==a[i-1])continue;int l=i+1,j=a.size()-1;while(l<j){long s=(long)a[i]+a[l]+a[j];if(s==0){r.push_back({a[i],a[l],a[j]});while(l<j&&a[l]==a[l+1])l++;while(l<j&&a[j]==a[j-1])j--;l++;j--;}else if(s<0)l++;else j--;}}return r;}};
