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
#     def connect(self, root: 'Node') -> 'Node':
#         res = []
#         def preorder(root, level):
#             if root:
#                 if level <= len(res):
#                     res.append([])
#                 res[level].append(root)
#                 preorder(root.left, level + 1)
#                 preorder(root.right, level + 1)
        
#         preorder(root, level = 0)
        
#         def listconnect(list):
#             length = len(list)
#             for i in range(length-1):
#                 list[i].next = list[i+1]
            
#         for l in res:
#             listconnect(l)
        
#         return root

# sol2, my, using queue. 
#     def connect(self, root: 'Node') -> 'Node':
#         if root is None:
#             return
        
#         q = collections.deque()
#         level = 0
#         q.append((root, level))
#         pre = None
#         pre_level = -1
        
#         while len(q) != 0:
            
#             (cur, level) = q.popleft()
#             if level == pre_level:
#                 pre.next = cur
#             pre_level = level
#             pre = cur
#             if cur.left:
#                 q.append((cur.left, level+1))
#             if cur.right:
#                 q.append((cur.right, level+1))
                
#         return root

# sol3, real solution by pochmann, no extra space
# https://leetcode.com/problems/populating-next-right-pointers-in-each-node/discuss/37484/7-lines-iterative-real-O(1)-space
    def connect(self, root: 'Node') -> 'Node':
        cur = root
        while(cur and cur.left):
            left = cur.left
            while cur:
                cur.left.next = cur.right
                if cur.next:
                    cur.right.next = cur.next.left
                cur = cur.next
            cur = left
        return root
