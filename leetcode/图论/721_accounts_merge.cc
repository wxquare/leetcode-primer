#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution { vector<int>p;int find(int x){return p[x]==x?x:p[x]=find(p[x]);}public:vector<vector<string>>accountsMerge(vector<vector<string>>&accounts){int n=accounts.size();p.resize(n);iota(p.begin(),p.end(),0);unordered_map<string,int>owner;for(int i=0;i<n;++i)for(int j=1;j<(int)accounts[i].size();++j){const string&e=accounts[i][j];if(owner.count(e))p[find(i)]=find(owner[e]);else owner[e]=i;}unordered_map<int,vector<string>>emails;for(const auto&e:owner)emails[find(e.second)].push_back(e.first);vector<vector<string>>ans;for(auto&entry:emails){sort(entry.second.begin(),entry.second.end());vector<string>row(1,accounts[entry.first][0]);row.insert(row.end(),entry.second.begin(),entry.second.end());ans.push_back(row);}return ans;} };
