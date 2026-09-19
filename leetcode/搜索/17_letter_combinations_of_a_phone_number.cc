#include <string>
#include <vector>
using namespace std;
class Solution { void dfs(int p,const string&d,string&cur,vector<string>&out,const string map[]){if(p==(int)d.size()){out.push_back(cur);return;}for(char c:map[d[p]-'0']){cur.push_back(c);dfs(p+1,d,cur,out,map);cur.pop_back();}} public:vector<string>letterCombinations(string digits){static const string map[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};vector<string>out;if(digits.empty())return out;string cur;dfs(0,digits,cur,out,map);return out;} };
