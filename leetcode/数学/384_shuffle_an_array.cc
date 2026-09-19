#include <vector>
using namespace std;
class Solution { vector<int> a; public: Solution(vector<int>& nums):a(nums){} vector<int> reset(){return a;} vector<int> shuffle(){vector<int>r=a;for(int i=1;i<r.size();++i)swap(r[i],r[rand()%(i+1)]);return r;} };
