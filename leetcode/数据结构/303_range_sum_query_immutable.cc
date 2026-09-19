#include <vector>
using namespace std; class NumArray{vector<int>s;public:NumArray(vector<int>&a):s(a.size()+1){for(int i=0;i<a.size();i++)s[i+1]=s[i]+a[i];}int sumRange(int l,int r){return s[r+1]-s[l];}};
