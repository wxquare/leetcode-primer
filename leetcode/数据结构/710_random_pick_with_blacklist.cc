#include <vector>
#include <unordered_map>
#include <cstdlib>
using namespace std; class Solution{int n;unordered_map<int,int>mp;public:Solution(int N,vector<int>&b){n=N-b.size();vector<char>x(N);for(int v:b)x[v]=1;int j=n;for(int v:b)if(v<n){while(x[j])j++;mp[v]=j++;}}int pick(){int x=rand()%n;return mp.count(x)?mp[x]:x;}};
