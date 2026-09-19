#include <map>
using namespace std; class CountIntervals{map<int,int>m;long long n=0;public:void add(int l,int r){auto it=m.lower_bound(l);if(it!=m.begin()&&prev(it)->second+1>=l)--it;while(it!=m.end()&&it->first<=r+1){l=min(l,it->first);r=max(r,it->second);n-=it->second-it->first+1;it=m.erase(it);}m[l]=r;n+=r-l+1;}int count(){return n;}};
