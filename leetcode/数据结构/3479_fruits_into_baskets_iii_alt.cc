#include <vector>
using namespace std; class FruitBasketSolution{public:int numOfUnplacedFruits(vector<int>&f,vector<int>&b){vector<char>u(b.size());int r=0;for(int x:f){int i=0;while(i<b.size()&&(u[i]||b[i]<x))i++;if(i==b.size())r++;else u[i]=1;}return r;}};
