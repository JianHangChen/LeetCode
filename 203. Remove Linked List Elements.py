# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # my sol1, O(n) space, not good using recursion
    # def removeElements(self, head: 'ListNode', val: 'int') -> 'ListNode':
    #     if head is None:
    #         return []
    #     if head.val == val:
    #         head = head.next
    #         return self.removeElements(head, val)
    #     pre = head
    #     cur = head.next
    #     while cur:
    #         if cur.val == val:
    #             pre.next = cur.next
    #             cur = cur.next
    #         else:
    #             pre = pre.next
    #             cur = cur.next
    #     return head
    
    # sol2, time O(n) space O(1)
    # https://leetcode.com/problems/remove-linked-list-elements/discuss/158651/Simple-Python-solution-with-explanation-(single-pointer-dummy-head).
        def removeElements(self, head: 'ListNode', val: 'int') -> 'ListNode':
            dummyhead = ListNode(-1)
            dummyhead.next = head
            cur = dummyhead
            while cur.next != None:
                if cur.next.val == val:
                    cur.next = cur.next.next
                else:
                    cur = cur.next
            return dummyhead.next
