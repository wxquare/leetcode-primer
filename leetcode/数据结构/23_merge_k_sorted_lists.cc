#include <vector>
#include <queue>
using namespace std; struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(0){}}; class Solution{public:ListNode* mergeKLists(vector<ListNode*>&a){auto cmp=[](ListNode*x,ListNode*y){return x->val>y->val;};priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)>q(cmp);for(auto*x:a)if(x)q.push(x);ListNode d(0),*p=&d;while(!q.empty()){p->next=q.top();q.pop();p=p->next;if(p->next)q.push(p->next);}return d.next;}};
