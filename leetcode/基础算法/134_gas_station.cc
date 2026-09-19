#include <vector>
using namespace std;
class Solution { public:int canCompleteCircuit(vector<int>& gas,vector<int>& cost){int total=0,tank=0,start=0;for(int i=0;i<gas.size();++i){int d=gas[i]-cost[i];total+=d;tank+=d;if(tank<0){tank=0;start=i+1;}}return total<0?-1:start;} };
