#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution { vector<int>p;int find(int x){return p[x]==x?x:p[x]=find(p[x]);}void unite(int a,int b){a=find(a);b=find(b);if(a!=b)p[a]=b;}public:bool gcdSort(vector<int>&a){int maximum=*max_element(a.begin(),a.end());p.resize(maximum+1);iota(p.begin(),p.end(),0);for(int value:a){int x=value;for(int factor=2;factor*factor<=x;++factor)if(x%factor==0){unite(value,factor);while(x%factor==0)x/=factor;}if(x>1)unite(value,x);}vector<int>b=a;sort(b.begin(),b.end());for(int i=0;i<(int)a.size();++i)if(find(a[i])!=find(b[i]))return false;return true;} };
