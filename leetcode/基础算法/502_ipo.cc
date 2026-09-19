#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution { public:int findMaximizedCapital(int k,int w,vector<int>& profits,vector<int>& capital){vector<pair<int,int>>a;for(int i=0;i<profits.size();++i)a.push_back({capital[i],profits[i]});sort(a.begin(),a.end());priority_queue<int>q;int i=0;while(k--){while(i<a.size()&&a[i].first<=w)q.push(a[i++].second);if(q.empty())break;w+=q.top();q.pop();}return w;} };
