//!!! sol1, practice more, 
//https://www.cnblogs.com/lichen782/p/leetcode_Reverse_Nodes_in_kGroup.html 

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || !head) return head;
        ListNode* dummy = new ListNode(-1);
        ListNode* pre = dummy, *cur = head;
        pre->next = head;
        
        for(int count = 1; cur; count++){
            if( count % k == 0){
                pre = reverse(pre, cur->next);
                cur = pre->next;
            }
            else{
                cur = cur->next;                
            }
            
        }
        return dummy->next;        
    }
    
    ListNode* reverse(ListNode* prehead, ListNode* tailnext){
        ListNode* last = prehead->next, *cur = last->next;
        
        while(cur != tailnext){
            last->next = cur->next;
            cur->next = prehead->next;
            prehead->next = cur;
            cur = last->next;
        }
        
        return last;
    }
};
