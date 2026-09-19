#include <string>
using namespace std; class Solution{public:string maximumBinaryString(string s){int z=0,p=-1;for(int i=0;i<s.size();i++)if(s[i]=='0')z++,p=i; if(z<=1)return s;for(char&c:s)c='1';s[p+z-1]='0';return s;}};
