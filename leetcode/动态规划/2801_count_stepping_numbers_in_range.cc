#include <string>
#include <vector>
using namespace std;
class Solution {string L;int K;long long dfs(int i,int p,bool t,bool lead){if(i==L.size())return !lead;long long r=0;int up=t?L[i]-'0':9;for(int x=0;x<=up;x++)if(lead||abs(x-p)<=1)r=(r+dfs(i+1,x,t&&x==up,lead&&x==0))%1000000007;return r;}long long f(string s){L=s;return dfs(0,0,1,1);}public:int countSteppingNumbers(string low,string high){long long a=f(high),b=f(to_string(stoll(low)-1));return (a-b+1000000007)%1000000007;}};
