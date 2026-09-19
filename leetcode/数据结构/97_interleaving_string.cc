#include <string>
#include <vector>
using namespace std; class Solution{public:bool isInterleave(string a,string b,string c){if(a.size()+b.size()!=c.size())return false;vector<char>d(b.size()+1);d[0]=1;for(int j=1;j<=b.size();j++)d[j]=d[j-1]&&b[j-1]==c[j-1];for(int i=1;i<=a.size();i++)for(int j=0;j<=b.size();j++)d[j]=(d[j]&&a[i-1]==c[i+j-1])||(j&&d[j-1]&&b[j-1]==c[i+j-1]);return d.back();}};
