/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// !!!my, O(m+n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while(l1 || l2){
            if(!l1 || (l1 && l2) && l1->val > l2->val){
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else{
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        return dummy->next;
        
    }
};


class Solution:

    # sol3: recursively from discuss
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        if l1 == None or l2 == None:
            return l1 or l2
        
        if l1.val <= l2.val:
            l1.next = self.mergeTwoLists(l1.next, l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l2.next, l1)
            return l2
    
# # sol2: iteratively,  small modification of sol1
# # https://leetcode.com/problems/merge-two-sorted-lists/discuss/9735/Python-solutions-(iteratively-recursively-iteratively-in-place).
#     def mergeTwoLists(self, l1, l2):
#         """
#         :type l1: ListNode
#         :type l2: ListNode
#         :rtype: ListNode
#         """
#         dummy = ListNode(0)
#         cur = dummy
#         while l1 and l2:
#             if l1.val <= l2.val:
#                 cur.next = l1
#                 l1 = l1.next
#             else:
#                 cur.next = l2
#                 l2 = l2.next
#             cur = cur.next
#         cur.next = l1 or l2
#         return dummy.next
        
    
    
#     # sol1: mine, not bad
#     def mergeTwoLists(self, l1, l2):
#         """
#         :type l1: ListNode
#         :type l2: ListNode
#         :rtype: ListNode
#         """
#         if l1 == None:
#             return l2
#         if l2 == None:
#             return l1
#         if l1.val <= l2.val:
#             head = l1
#             l1 = l1.next
#         else:
#             head = l2
#             l2 = l2.next
#         current = head
#         # while not (l1 == None and l2 == None):
#         while True:
#             if l1 == None:
#                 current.next = l2
#                 break
#             elif l2 == None:
#                 current.next = l1
#                 break
#             elif l1.val <= l2.val:
#                 current.next = l1
#                 current = l1
#                 l1 = l1.next
#             else:
#                 current.next = l2
#                 current = l2
#                 l2 = l2.next
#         return head
    
#         # array thinking behind my sol1
#         # len1 = len(l1)
#         # len2 = len(l2)
#         # i1 = 0
#         # i2 = 0
#         # while not (i1==len1 and i2==len2):
#         #     if i1 == len1:
#         #         newl[i1+i2] = l2[i2]
#         #         i2 += 1
#         #     elif i2 == len2:
#         #         newl[i1+i2] = l1[i1]
#         #         i1 += 1
#         #     elif l1[i1] <= l2[i2]:
#         #         newl[i1+i2] = l1[i1]
#         #         i1 += 1
#         #     else:
#         #         new[i1+i2] = l2[i2]
#         #         i2 += 1
