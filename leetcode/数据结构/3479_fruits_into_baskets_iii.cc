#include <vector>
using namespace std; class Solution{public:int numOfUnplacedFruits(vector<int>&f,vector<int>&b){int r=0;vector<char>u(b.size());for(int x:f){int j=0;while(j<b.size()&&(u[j]||b[j]<x))j++;if(j==b.size())r++;else u[j]=1;}return r;}};
