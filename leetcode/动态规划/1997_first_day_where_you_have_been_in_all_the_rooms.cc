#include <vector>
using namespace std;
class Solution { public: int firstDayBeenInAllRooms(vector<int>& nextVisit) { const long long M=1000000007; long long d=0; vector<long long> f(nextVisit.size()); for(int i=1;i<(int)nextVisit.size();i++){ f[i]=(2*f[i-1]-f[nextVisit[i-1]]+2+M)%M; } return (int)f.back(); } };
