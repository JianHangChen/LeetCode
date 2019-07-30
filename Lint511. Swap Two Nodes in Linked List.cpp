class Solution {
public:
    /**
     * @param head: a ListNode
     * @param v1: An integer
     * @param v2: An integer
     * @return: a new head of singly-linked list
     */
    ListNode * swapNodes(ListNode * head, int v1, int v2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* pre, *cur, *pre1 = NULL, *cur1 = NULL, *pre2 = NULL, * cur2 = NULL;
        pre = dummy; cur = dummy->next;
        
        while(cur){
            if(cur->val == v1 || cur->val == v2){
                if(pre1 == NULL){
                    pre1 = pre;
                    cur1 = cur;
                }
                else{
                    pre2 = pre;
                    cur2 = cur;
                    break;
                }
            }
            pre = cur;
            cur = cur->next;
        }
        
        if(cur1 == NULL || cur2 == NULL) return dummy->next;

        pre1->next = cur2;
        pre2->next = cur1;
        ListNode* tmp = cur1->next;
        cur1->next = cur2->next;
        cur2->next = tmp;

        return dummy->next;
        
    }
};
