   bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        
        ListNode* mid = findMid(head);
        ListNode* end = reverse(mid->next);
        
        
        ListNode* cur = head;
        ListNode* rcur = end;
        cout << rcur->val;
        while(rcur != NULL){
            if (cur->val != rcur->val){
                mid->next = reverse(end);
                return false;
            }
            rcur = rcur->next;
            cur = cur->next;
        }
        mid->next = reverse(end);# here is important to maintain original list
        return true;
        
    }
    
    ListNode* findMid(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
        
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next;
        
        while (cur != NULL) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
