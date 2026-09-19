#include <deque>
using namespace std; class MaxQueue{deque<int>q,m;public:MaxQueue(){}int max_value(){return m.empty()?-1:m.front();}void push_back(int v){q.push_back(v);while(!m.empty()&&m.back()<v)m.pop_back();m.push_back(v);}int pop_front(){if(q.empty())return -1;int v=q.front();q.pop_front();if(v==m.front())m.pop_front();return v;}};
