#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std; class Solution{public:int ladderLength(string b,string e,vector<string>&w){unordered_set<string>s(w.begin(),w.end());if(!s.count(e))return 0;queue<string>q;q.push(b);int d=1;while(!q.empty()){for(int z=q.size();z--;){string x=q.front();q.pop();if(x==e)return d;for(int i=0;i<x.size();i++){char c=x[i];for(char y='a';y<='z';y++){x[i]=y;if(s.count(x))s.erase(x),q.push(x);}x[i]=c;}}d++;}return 0;}};
