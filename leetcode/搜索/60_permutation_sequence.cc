#include <string>
#include <vector>
using namespace std;
class Solution { public:string getPermutation(int n,int k){vector<int>a;int f=1;for(int i=1;i<n;++i){a.push_back(i);f*=i;}a.push_back(n);--k;string s;for(int i=n;i>=1;--i){int p=k/f;k%=f;f=i>1?f/(i-1):1;s+=char('0'+a[p]);a.erase(a.begin()+p);}return s;} };
