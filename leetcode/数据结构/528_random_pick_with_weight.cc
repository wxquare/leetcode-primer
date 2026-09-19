#include <vector>
#include <cstdlib>
using namespace std; class Solution{vector<int>p;public:Solution(vector<int>&w){int s=0;for(int x:w)s+=x,p.push_back(s);}int pickIndex(){int x=rand()%p.back()+1;int l=0,r=p.size()-1;while(l<r){int m=(l+r)/2;if(p[m]<x)l=m+1;else r=m;}return l;}};
