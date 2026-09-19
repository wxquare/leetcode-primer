#include <algorithm>
using namespace std;
class Solution {
    bool valid(long long n, long long k, int x) {
        long long count=0;
        for (int bit=x; bit<62; bit+=x) {
            long long half=1LL<<(bit-1), period=1LL<<bit;
            count += (n+1)/period*half + max(0LL, (n+1)%period-half);
            if (count>k) return false;
        }
        return count<=k;
    }
public:
    long long findMaximumNumber(long long k, int x) { long long l=0,r=1000000000000000LL; while(l<r){long long m=l+(r-l+1)/2; if(valid(m,k,x)) l=m; else r=m-1;} return l; }
};
