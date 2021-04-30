

//!!! sol2, O(n), O(1) 
// 不容易写对
// 12345
// 15243
// 1. find middle 2. reverse 3. merge 2
class Solution {
public:
    void reorderList(ListNode* head) {
        
        // 1234
        //  sm
        //   f
        
        // 1. find mid
        ListNode* s = head, *f = head;
        while(f->next && f->next->next){
            s = s->next;
            f = f->next->next;
        }
        ListNode* m = s->next;
        s->next = NULL; // !!!! very easy to have bug

        // null<-3<-4
        //             c
        //          p   n

        // 2. reverse
        ListNode* cur = m, *next = m, * pre = NULL;

        while(cur){
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
        // 3. merge2
        // 12  43
        // 1->4->2   3
        //       i   j
        //  ni  nj
        ListNode* i = head, *j = pre, *next_i, *next_j;
        
        while(j){
            next_i = i->next;
            next_j = j->next;
            i->next = j;
            j->next = next_i;
            
            i = next_i;
            j = next_j;
        }
                
        
    }
};


// sol1, my, O(n), O(n)
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        
        vector<ListNode*> a;
        while(head){
            a.push_back(head);
            head = head->next;
        }
        
        int i = 0, j = a.size() - 1;
        
        while(i < j){
            a[i]->next = a[j];
            a[j]->next = a[++i];
            j--;
        }
        a[i]->next = NULL;
        
    }
};
