#include <string>
#include <vector>
using namespace std;
class Solution { public: long long validSubstringCount(string word1,string word2){vector<int> need(26);int missing=word2.size();for(char c:word2)++need[c-'a'];long long ans=0;for(int l=0,r=0;r<word1.size();++r){if(need[word1[r]-'a']-->0)--missing;while(!missing){ans+=word1.size()-r;if(++need[word1[l++]-'a']>0)++missing;}}return ans;} };
