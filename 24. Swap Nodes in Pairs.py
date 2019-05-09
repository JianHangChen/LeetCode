# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
        # sol1: iterative

    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        previous = dummy = ListNode(0)
        dummy.next = head
        
        while previous.next and previous.next.next:
            p1 = previous.next
            p2 = previous.next.next
            previous.next, p1.next, p2.next = p2, p2.next, p1 
            previous = p1
            

        return dummy.next
            
    # sol2 recursive
    def swapPairs(self, head: ListNode) -> ListNode:
        dummy = ListNode
        if head:
            if head.next:
                dummy = head.next
                head.next = self.swapPairs(dummy.next)
                dummy.next = head
            else:
                return head           
        
            return dummy
