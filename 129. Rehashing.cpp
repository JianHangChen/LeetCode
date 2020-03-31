/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
 
//!!! my sol2.1, use original node, for the new linklist, insert to the head instead of tail
// this cannot pass the oa, but that's the best answer in real implementation
 
// class Solution {
// public:

//     vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
//         int n = hashTable.size();
//         int l = n * 2;
//         vector<ListNode*> res(l);
//         for(auto& node:hashTable){
//             while(node){
//                 int val = node->val;
//                 int pos = (val % l + l) % l;
//                 auto next_node = node->next;
//                 if(res[pos] == NULL){
//                     res[pos] = node;
//                     node->next= NULL;
//                 }
//                 else{
//                     node->next = res[pos];
//                     res[pos] = node;
//                 }
//                 node = next_node;
//             }
//         }
//         return res;
//     }
// };


 //!!!! my sol2, use original node
class Solution {
public:

    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int n = hashTable.size();
        int l = n * 2;
        vector<ListNode*> res(l);
        for(auto& node:hashTable){
            while(node){
                int val = node->val;
                int pos = (val % l + l) % l;
                auto next_node = node->next;
                if(res[pos] == NULL){
                    res[pos] = node;
                }
                else{
                    ListNode* cur = res[pos];
                    while(cur->next){
                        cur = cur->next;
                    }
                    cur->next = node;
                }
                node->next= NULL;
                node = next_node;
            }
        }
        return res;
    }
};

 
// my sol1, use new space
// class Solution {
// public:

//     vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
//         int n = hashTable.size();
//         int l = n * 2;
//         vector<ListNode*> res(l);
//         for(auto& node:hashTable){
//             while(node){
//                 int val = node->val;
//                 int pos = (val % l + l) % l;
//                 if(res[pos] == NULL){
//                     res[pos] = new ListNode(val);
//                 }
//                 else{
//                     ListNode* cur = res[pos];
//                     while(cur->next){
//                         cur = cur->next;
//                     }
//                     cur->next = new ListNode(val);
//                 }
//                 node = node->next;
//             }
//         }
//         return res;
//     }
// };
