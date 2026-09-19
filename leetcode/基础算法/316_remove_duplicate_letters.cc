#include <string>
#include <vector>
using namespace std;
class Solution { public:string removeDuplicateLetters(string s){vector<int>last(26),used(26);for(int i=0;i<s.size();++i)last[s[i]-'a']=i;string st;for(int i=0;i<s.size();++i){int c=s[i]-'a';if(used[c])continue;while(!st.empty()&&st.back()>s[i]&&last[st.back()-'a']>i){used[st.back()-'a']=0;st.pop_back();}st+=s[i];used[c]=1;}return st;} };
