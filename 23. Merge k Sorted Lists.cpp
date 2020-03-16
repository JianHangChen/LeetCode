/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// !!!!! sol3, divide and conquer, merge two sorted list
// O(nlogk), O(1)

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){  
        int k = lists.size();
        if(k == 0) return NULL;
        while(k > 1){
            for(int i = 0; i < k / 2; i++){
                lists[i] = mergeTwoLists(lists[2*i], lists[2*i+1]);
            }
            if(k % 2 != 0) lists[k/2] = lists[k-1];
            k = (k % 2 == 0) ? k/2 : k/2+1;            
        }
        
        return lists[0];        
    }
    ListNode* mergeTwoLists(ListNode* a, ListNode* b){
        ListNode* dummy = new ListNode(-1), * cur = dummy;
        while(a || b){
            if(!a || (a && b) && (a->val > b->val)){
                cur->next = b;
                cur = b;
                b = b->next;
            }
            else{
                cur->next = a;
                cur = a;
                a = a->next;
            }
        }
        
        return dummy->next;     
    }
};

//!!!sol2,  using priority queue, O(nlogk), O(k) same as gy2 and sol3
// class Solution {
// public:
//     struct CMP{
//         bool operator() (const ListNode* a, const ListNode* b){
//             return (a->val) > (b->val);
//         }
//     };
    
//     ListNode* mergeKLists(vector<ListNode*>& lists){  
        
//         ListNode* dummy = new ListNode(0);
//         ListNode* pre = dummy, *t;
        
//         priority_queue<ListNode*, vector<ListNode*>, CMP> pq;
                
//         for(auto list:lists){
//             if(list) pq.push(list);
//         }
        
//         while(!pq.empty()){
//             t = pq.top(); pq.pop();
//             pre->next = t;
//             pre = t;
            
//             if(t->next) pq.push(t->next);

//         }        
//         return dummy->next;       
        
        
//     }
// };

// sol1, my compare one by one, O(nk), same as sol2
// n is total number of node, k is the number of lists
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode* dummy = new ListNode(0);
//         ListNode* pre = dummy, *cur;
        
//         int emptylist = 0;
        
//         while(true){
//             emptylist = 0;
//             int idx;
//             cur = NULL;
            
//             for(int i = 0 ; i < lists.size(); i++){
//                 if(!lists[i]){
//                     emptylist++;
//                     continue;
//                 }
//                 if(!cur || lists[i]->val < cur->val){
//                     cur = lists[i];
//                     idx = i;
//                 }
//             }
//             if(emptylist == lists.size()) break;
//             pre->next = cur;
//             pre = cur;
//             lists[idx] = lists[idx]->next;
            
//         }
//         return dummy->next;       
        
        
//     }
// };
