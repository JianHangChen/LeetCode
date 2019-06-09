    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first, * second;
        first = dummy;
        second = dummy;
        
        int count = 0;
        while(count <= n){
            second = second->next;
            count++;
        }
        
        while(second){
            second = second->next;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next; 
    }
