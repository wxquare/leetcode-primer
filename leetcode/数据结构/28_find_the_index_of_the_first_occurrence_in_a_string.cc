#include <string>
using namespace std; class Solution{public:int strStr(string h,string n){if(n.empty())return 0;for(int i=0;i+n.size()<=h.size();i++){int j=0;while(j<n.size()&&h[i+j]==n[j])j++;if(j==n.size())return i;}return -1;}};
