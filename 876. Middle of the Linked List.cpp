
//     //sol1, my, two pointer

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* first, *second;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        first = dummy; second = dummy;
        
        while(first && second){
            first = first->next;
            second = second->next;
            if(!second) break;
            second = second->next;
        }
        return first;
    }
    

    
};

 //sol1.1, two pointer form sol2, just no need for dummy
class Solution {
public:
     ListNode* middleNode(ListNode* head) {
         ListNode* slow, * fast;
         slow = head; fast = head;
         
         while(fast && fast->next){
             slow = slow->next;
             fast = fast->next->next;
         }
         return slow;
         
     }   
    
};
