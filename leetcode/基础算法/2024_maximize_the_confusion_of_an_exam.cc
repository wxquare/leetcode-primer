#include <string>
using namespace std;
class Solution { int longest(string&s,int k,char x){int l=0,bad=0,ans=0;for(int r=0;r<s.size();++r){bad+=s[r]!=x;while(bad>k)bad-=s[l++]!=x;ans=max(ans,r-l+1);}return ans;} public:int maxConsecutiveAnswers(string answerKey,int k){return max(longest(answerKey,k,'T'),longest(answerKey,k,'F'));} };
