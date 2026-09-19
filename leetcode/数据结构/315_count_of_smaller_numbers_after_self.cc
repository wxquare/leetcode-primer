#include <vector>
using namespace std; class Solution{public:vector<int> countSmaller(vector<int>&a){vector<int>r(a.size());for(int i=0;i<a.size();i++)for(int j=i+1;j<a.size();j++)r[i]+=a[j]<a[i];return r;}};
