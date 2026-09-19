#include <vector>
#include <map>
using namespace std;
class Solution { public:vector<int> findOriginalArray(vector<int>& changed){if(changed.size()%2)return {};map<int,int>cnt;for(int x:changed)++cnt[x];vector<int>ans;for(map<int,int>::iterator it=cnt.begin();it!=cnt.end();++it){int x=it->first,c=it->second;if(x==0){if(c%2)return {};for(int i=0;i<c/2;++i)ans.push_back(0);}else{if(c>cnt[x*2])return {};for(int i=0;i<c;++i){ans.push_back(x);--cnt[x*2];}}}return ans;} };
