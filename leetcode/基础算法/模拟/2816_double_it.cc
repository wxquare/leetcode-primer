#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(nullptr){}
    ListNode(int x,ListNode* next):val(x),next(next){}
};

class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* dummy = new ListNode(-1);
        ListNode* p = head;
        while(p){ 
            ListNode *next = p->next;
            p->next = dummy->next;
            dummy->next = p;
            p = next;
        }
        return dummy->next;
    }
    ListNode* doubleIt(ListNode *head){
        head = reverse(head);
        ListNode* dummy = new ListNode(-1);
        ListNode* p = head;
        int carry = 0;
        ListNode* q = dummy;
        while(carry != 0 || p){
            int val = carry;
            if(p){
                val += p->val * 2;
            }
            carry = val / 10;
            val = val % 10;
            q->next = new ListNode(val);
            if(p) p = p->next;
            q = q->next;
        }
        ListNode* ans = reverse(dummy->next);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(8);
    ListNode* n3 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    ListNode* ans = Solution().doubleIt(n1);
    ListNode* p = ans;
    while(p){
        std::cout << p->val << std::endl;
        p = p->next;
    }
    return 0;
}
