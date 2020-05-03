/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// sol1, my, O(max(m, n)), O(max(m, n))
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            cur->next =  new ListNode(carry);
            cur = cur->next;
            
            if(l1){ cur->val += l1->val; l1 = l1->next;}
            if(l2){ cur->val += l2->val; l2 = l2->next;}
            if(cur->val >= 10){
                cur->val -= 10;
                carry = 1;
            }
            else{
                carry = 0;
            }
        }
        return dummy->next;
    }
};
