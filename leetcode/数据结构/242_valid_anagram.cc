#include <string>
using namespace std; class Solution{public:bool isAnagram(string a,string b){if(a.size()!=b.size())return false;int c[26]={};for(char x:a)c[x-'a']++;for(char x:b)if(--c[x-'a']<0)return false;return true;}};
