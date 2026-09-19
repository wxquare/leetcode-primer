#include <string>
using namespace std; class Solution{public:bool isIsomorphic(string a,string b){int x[256]={},y[256]={};for(int i=0;i<a.size();i++){if(x[(unsigned char)a[i]]!=y[(unsigned char)b[i]])return false;x[(unsigned char)a[i]]=y[(unsigned char)b[i]]=i+1;}return true;}};
