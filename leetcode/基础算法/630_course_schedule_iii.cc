#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution { public:int scheduleCourse(vector<vector<int>>& courses){sort(courses.begin(),courses.end(),[](const vector<int>&a,const vector<int>&b){return a[1]<b[1];});priority_queue<int>q;int t=0;for(auto&c:courses){t+=c[0];q.push(c[0]);if(t>c[1]){t-=q.top();q.pop();}}return q.size();} };
