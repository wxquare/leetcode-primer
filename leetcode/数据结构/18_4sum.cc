#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;
class Solution {public:vector<vector<int>> fourSum(vector<int>&a,int t){sort(a.begin(),a.end());vector<vector<int>>r;for(int i=0;i<a.size();i++){if(i&&a[i]==a[i-1])continue;for(int j=i+1;j<a.size();j++){if(j>i+1&&a[j]==a[j-1])continue;int l=j+1,h=a.size()-1;while(l<h){long s=(long)a[i]+a[j]+a[l]+a[h];if(s==t){r.push_back({a[i],a[j],a[l],a[h]});while(l<h&&a[l]==a[l+1])l++;while(l<h&&a[h]==a[h-1])h--;l++;h--;}else if(s<t)l++;else h--;}}}return r;}};
