#include <vector>
#include <numeric>
#include <algorithm>
#include <cstdlib>
using namespace std;
class Solution { public:int findMinMoves(vector<int>& machines){int sum=accumulate(machines.begin(),machines.end(),0),n=machines.size();if(sum%n)return -1;int avg=sum/n,flow=0,ans=0;for(int x:machines){flow+=x-avg;ans=max(ans,max(abs(flow),x-avg));}return ans;} };
