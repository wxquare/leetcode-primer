#include <vector>
#include <algorithm>
using namespace std;
class Solution {public:int minOperations(vector<int>&nums,int sum){const int I=1000000000;vector<int>d(sum+1,I);d[0]=0;for(int x:nums)for(int w=sum;w>=0;w--){int y=x,c=0;while(y<=w){d[w]=min(d[w],d[w-y]+c);y*=2;c++;}y=x/2;c=1;while(y){if(y<=w)d[w]=min(d[w],d[w-y]+c);y/=2;c++;}}return d[sum]==I?-1:d[sum];}};
