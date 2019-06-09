     ListNode* middleNode(ListNode* head) {
         ListNode* slow, * fast;
         slow = head; fast = head;
         
         while(fast && fast->next){
             slow = slow->next;
             fast = fast->next->next;
         }
         return slow;
         
     }   
