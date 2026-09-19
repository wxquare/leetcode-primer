#include <vector>
#include <algorithm>
using namespace std;
class Solution { vector<int> pick(const vector<int>&a,int k){vector<int>s;int drop=a.size()-k;for(int x:a){while(drop&&!s.empty()&&s.back()<x)s.pop_back(),--drop;s.push_back(x);}s.resize(k);return s;} bool better(const vector<int>&a,const vector<int>&b){for(int i=0;i<a.size();++i)if(i>=b.size()||a[i]!=b[i])return i>=b.size()||a[i]>b[i];return false;} public:vector<int> maxNumber(vector<int>&a,vector<int>&b,int k){vector<int>ans;for(int x=0;x<=k;++x)if(x<=a.size()&&k-x<=b.size()){vector<int>p=pick(a,x),q=pick(b,k-x),c;int i=0,j=0;while(i<p.size()||j<q.size()){bool take=i<p.size()&&(j==q.size()||lexicographical_compare(q.begin()+j,q.end(),p.begin()+i,p.end()));c.push_back(take?p[i++]:q[j++]);}if(better(c,ans))ans=c;}return ans;} };
