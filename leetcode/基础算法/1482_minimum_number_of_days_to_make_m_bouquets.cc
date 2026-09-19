#include <vector>
#include <algorithm>
using namespace std;
class Solution { public:int minDays(vector<int>& bloomDay,int m,int k){if(1LL*m*k>bloomDay.size())return -1;int lo=1,hi=*max_element(bloomDay.begin(),bloomDay.end());auto ok=[&](int d){int run=0,c=0;for(int x:bloomDay){if(x<=d){if(++run==k){++c;run=0;}}else run=0;}return c>=m;};while(lo<hi){int mid=lo+(hi-lo)/2;if(ok(mid))hi=mid;else lo=mid+1;}return lo;} };
