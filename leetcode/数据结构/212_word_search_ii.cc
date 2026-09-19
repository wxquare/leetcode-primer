#include <vector>
#include <string>
#include <unordered_set>
using namespace std; class Solution{unordered_set<string>words;vector<string>r;vector<vector<int>>d{{1,0},{-1,0},{0,1},{0,-1}};void f(vector<vector<char>>&b,int i,int j,string&s){if(i<0||j<0||i>=b.size()||j>=b[0].size()||b[i][j]=='#')return;s+=b[i][j];if(words.count(s)){r.push_back(s);words.erase(s);}for(auto&x:d){char c=b[i][j];b[i][j]='#';f(b,i+x[0],j+x[1],s);b[i][j]=c;}s.pop_back();}public:vector<string> findWords(vector<vector<char>>&b,vector<string>&w){words=unordered_set<string>(w.begin(),w.end());string s;for(int i=0;i<b.size();i++)for(int j=0;j<b[0].size();j++)f(b,i,j,s);return r;}};
