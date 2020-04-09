/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
//     //sol1, my, two pointer
    ListNode* middleNode(ListNode* head) {
        ListNode* first,* second;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        first = dummy;
        second = dummy;
        while(second){
            first = first->next;
            if(second->next){
                second = second->next->next;
            }
            else{
                break;
            }
        }
        return first;
        
    }
    
    //sol1.1, two pointer form sol2, just no need for dummy
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
