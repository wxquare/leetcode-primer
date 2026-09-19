#include <vector>
using namespace std; struct ListNode{int val;ListNode*next;ListNode(int x):val(x),next(0){}}; class Solution{public:ListNode* deleteDuplicates(ListNode*h){for(ListNode*p=h;p&&p->next;)if(p->val==p->next->val)p->next=p->next->next;else p=p->next;return h;}};
