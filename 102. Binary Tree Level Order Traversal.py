# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# my sol1, using queue
# class Solution:
#     def levelOrder(self, root: TreeNode) -> List[List[int]]:
#         q = collections.deque()
#         if root:
#             q.append(root)
#         res = []
#         while len(q)!= 0:
#             res.append([])
#             l = len(q)
#             for _ in range(l):
#                 p = q.popleft()
#                 if p.left:
#                     q.append(p.left)
#                 if p.right:
#                     q.append(p.right)
#                 res[-1].append(p.val)
#         return res

# sol2, using list in python
# from https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33464/5-6-lines-fast-python-solution-(48-ms)
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        res = []
        level = [root]
        while root and level:
            res.append([node.val for node in level])
            
            # 2.1
            # temp = []
            # for node in level:
            #     if node.left:
            #         temp.append(node.left)
            #     if node.right:
            #         temp.append(node.right)
            # level = temp
            
            # 2.2
            # level = [leaf for node in level for leaf in (node.left, node.right) if leaf]
            
            # 2.3
            LRpairs = [(node.left, node.right) for node in level]
            level = [leaf for pair in LRpairs for leaf in pair if leaf]
            
        return res
