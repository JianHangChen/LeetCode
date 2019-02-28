"""
# Definition for a Node.
class Node:
    def __init__(self, val, left, right, next):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    
    # sol1, my, use extra space
    # def connect(self, root: 'Node') -> 'Node':
#         def findson(cur):
#             sons = []
#             while cur:
#                 if cur.left:
#                     sons.append(cur.left)
#                 if cur.right:
#                     sons.append(cur.right)
#                 cur = cur.next
#             return sons
        
#         cur = root
#         while cur:
#             sons = findson(cur)
#             if sons == []:
#                 break
#             else:
#                 for i in range(len(sons)-1):
#                     sons[i].next = sons[i+1]
#                 cur = sons[0]
#         return root

    # sol2, dummy node
    # from https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/discuss/37824/AC-Python-O(1)-space-solution-12-lines-and-easy-to-understand
    
    def connect(self, root: 'Node') -> 'Node':
        dummy = Node(-1, None, None, None)
        pre = dummy
        cur = root
        while cur:
            pre.next = cur.left
            if cur.left:
                pre = cur.left
            pre.next = cur.right
            if cur.right:
                pre = cur.right
            
            cur = cur.next
            if not cur:
                cur = dummy.next
                pre = dummy
        return root
