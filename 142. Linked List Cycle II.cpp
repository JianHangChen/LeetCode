//!!! my O(n), O(1), same as sol1
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        while(fast){
            fast = fast->next;
            if(!fast) break;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        if(!fast) return NULL;
        ListNode* p = head;
        while(p != slow){
            p = p->next;
            slow = slow->next;
        }
        return slow;
        
    }
};
