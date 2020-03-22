/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// !!! sol2, iteratively
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        
        while(pre->next){
            ListNode* cur = pre->next;
            if(!cur->next) break;
            if(cur->val == cur->next->val){
                while(cur && cur->next && cur->val == cur->next->val ){
                    cur = cur->next;
                }
                pre->next = cur->next;
            }
            else{
                pre = pre->next;
            }
        }
        return dummy->next;
    }
};
    

// !sol3, my, recursively, easy to implement
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head) return head;
        if(!head->next) return head;
        
        
        if(head->val != head->next->val){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        while(head && head->next && head->val == head->next->val){
            head = head->next;
        }
        return deleteDuplicates(head->next);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//sol1, my
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        
        while(cur && cur->next){
            if(cur->val != cur->next->val){
               pre = cur;
                cur = cur->next;
            }
            else{
                while(cur->next && cur->val == cur->next->val){
                    cur = cur->next;
                }
                pre->next = cur->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
    
};

// sol2,similar but better!!!
class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* pre = dummy;
        
        while(pre->next){
            ListNode* cur = pre->next;
            
            while(cur && cur->next && cur->next->val == cur->val){
                    cur = cur->next;
            }
            
            if(pre->next != cur) pre->next = cur->next;
            else{
                pre = cur;
            }
        }
        return dummy->next;
        
    }
};

// sol3, recursively

class Solution{
public:
    ListNode* deleteDuplicates(ListNode* head){
        if(!head || !head->next) return head;
        
        if(head->next->val == head->val){
            while(head->next && head->next->val == head->val){
                head = head->next;
            }
            return deleteDuplicates(head->next);
        }
        else{
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }    
};
