#include <queue>
#include <vector>
using namespace std; class KthLargest{int k;priority_queue<int,vector<int>,greater<int>>q;public:KthLargest(int K,vector<int>&a):k(K){for(int x:a)add(x);}int add(int x){q.push(x);if(q.size()>k)q.pop();return q.top();}};
