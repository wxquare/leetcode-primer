#include <algorithm>
#include <vector>
using namespace std;
class Solution { void dfs(int p,vector<int>&a,vector<vector<int> >&out){if(p==(int)a.size()){out.push_back(a);return;}for(int i=p;i<(int)a.size();++i){bool used=false;for(int j=p;j<i;++j)if(a[j]==a[i])used=true;if(used)continue;swap(a[p],a[i]);dfs(p+1,a,out);swap(a[p],a[i]);}} public:vector<vector<int> >permuteUnique(vector<int>&nums){vector<vector<int> >out;sort(nums.begin(),nums.end());dfs(0,nums,out);return out;} };
