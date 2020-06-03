/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


//!!! sol2, from sol, O(1), O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

// sol1, my, change everynode after that node, O(n), O(1)
// class Solution {
// public:
//     void deleteNode(ListNode* node) {
//         while(node && node->next){
//             node->val = node->next->val;
//             if(!node->next->next) break;            
//             node = node->next;
            
//         }
//         if(node) node->next = NULL;
//     }
// };
